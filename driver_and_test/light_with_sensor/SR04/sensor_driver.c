#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/input.h>
#include <linux/init.h>
#include <linux/errno.h>
#include <linux/serio.h>
#include <linux/delay.h>
#include <linux/clk.h>
#include <linux/wait.h>
#include <linux/sched.h>
#include <linux/cdev.h>
#include <linux/miscdevice.h>
#include <linux/gpio.h>
// #include <mach/gpio.h>
//#include <asm-generic/uaccess.h>
#include <linux/spinlock.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/delay.h>
#include <linux/uaccess.h>  //copy_to/from_user()
#include <linux/gpio.h>     //GPIO
#include <linux/err.h>
#include <linux/sched.h>
#include <linux/ktime.h>
#include <linux/interrupt.h>
#include <linux/irqreturn.h>
#include <linux/timekeeping.h>


#define ECHO (8)
#define TRIG (25)



#define DEVICE_MAJOR 206
#define DEVICE_NAME "HC-SR04"

#define BUF_LEN 1

typedef unsigned char U8;
unsigned char buf[BUF_LEN];
unsigned char temp = 0;
static unsigned int gpio_irq;
static unsigned int gpio_pin = ECHO;
static ktime_t start_time;
static ktime_t end_time;
static int busyflag = 1;


static irqreturn_t timerup(int irq, void *dev_id)
{
	if(gpio_get_value(ECHO)){
		start_time = ktime_get();
		printk("timer start");
	}
	else
	{
	end_time = ktime_get();
	printk("timer stop");
	busyflag = 0;
	}
	
	return IRQ_HANDLED;
}


void gpio_out(int PI ,int value)   //set gpio is output
{
    gpio_direction_output(PI,value);
}


void read_data(void)
{
	gpio_out(TRIG,0);
	udelay(2);
    gpio_out(TRIG,1);
    udelay(10);
    gpio_out(TRIG,0);
	printk("read_data done");
}


static int test_open(struct inode *inode, struct file *file)
{
	busyflag = 1;
	printk("open in kernel\n");
	return 0;
}


static ssize_t test_read(struct file *file, char* buffer,size_t size ,loff_t *off)
{
		int ret;
		while (busyflag);
		buf[0] = (ktime_to_us(ktime_sub(end_time, start_time)) * 343 / 2 / 10000);
		printk("busyflag done");
		ret = copy_to_user(buffer,buf,sizeof(buf));
		printk("%d",buf[0]);
		busyflag = 1;
		if(ret < 0)
			{
				printk("copy to user err\n");
				return -EAGAIN;
            }
            else
            {
            	return 0;
			}
		return 0;
}

static ssize_t test_write(struct file *file, const char *buffer, size_t size, loff_t *off)
{
	read_data();
	return size;
}



static int test_release(struct inode *inode, struct file *file)
{
	printk("test release\n");
	return 0;
}

static struct file_operations HC_dev_fops={
	owner	:	THIS_MODULE,
	open	:	test_open,
	read	:	test_read,
	write	:	test_write,
	release	:	test_release,
};
static struct class *HC_class;

static int __init test_init(void)
{
	int ret;
	int result;
	busyflag = 1;

	ret =register_chrdev(DEVICE_MAJOR, DEVICE_NAME, &HC_dev_fops);
	if (ret < 0) {
		printk(KERN_INFO "%s: registering device %s with major %d failed with %d\n",
		__func__, DEVICE_NAME, DEVICE_MAJOR, DEVICE_MAJOR );
		return(ret);
		}
	printk("test driver register success!\n");

	HC_class = class_create(THIS_MODULE, "HC");
		if(IS_ERR(HC_class))
		{
			printk(KERN_WARNING "CANT MAKE NODE %d\n",DEVICE_MAJOR);
				return PTR_ERR(HC_class);
		}

		device_create(HC_class, NULL, MKDEV(DEVICE_MAJOR, 0), NULL, DEVICE_NAME);

		printk("test driver make node success!\n");

	
	if( gpio_request( ECHO, DEVICE_NAME ) < 0 )	// request pin ECHO
	{
		printk( KERN_INFO "%s: %s unable to get TRIG gpio\n", DEVICE_NAME, __func__ );
		ret = -EBUSY;
		return(ret);
	}
	
	if( gpio_request( TRIG, DEVICE_NAME ) < 0 )	// request pin TRIG 
	{
		printk( KERN_INFO "%s: %s unable to get TRIG gpio\n", DEVICE_NAME, __func__ );
		ret = -EBUSY;
		return(ret);
	}
	

	gpio_out(TRIG,0);
	gpio_direction_input(ECHO);
	
	gpio_irq = gpio_to_irq(ECHO);
    if (gpio_irq < 0) {
        printk(KERN_ERR "Unable to get IRQ number for GPIO pin %d\n", gpio_pin);
        gpio_free(gpio_pin);
        return gpio_irq;
    }
	result = request_irq(gpio_irq, timerup , IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING, "gpio_irq", NULL);
    if (result) {
        printk(KERN_ERR "Unable to request IRQ %d\n", gpio_irq);
        gpio_free(gpio_pin);
        return result;
    }


    printk(KERN_INFO "GPIO interrupt module initialized\n");
	

	return 0 ;
}

static void __exit test_exit(void)
{
	free_irq(gpio_irq, NULL);
	gpio_free(ECHO);
	gpio_free(TRIG);
	device_destroy(HC_class,DEVICE_MAJOR);
	class_destroy(HC_class);
	unregister_chrdev(DEVICE_MAJOR, DEVICE_NAME);
}
module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sr");
