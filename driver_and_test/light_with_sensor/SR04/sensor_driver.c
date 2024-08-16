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




#define ECHO (8)
#define TRIG (25)



#define DEVICE_MAJOR 206
#define DEVICE_NAME "HC-SR04"

#define BUF_LEN 2

typedef unsigned char U8;
unsigned char buf[BUF_LEN];
unsigned char temp = 0;


void gpio_out(int PI ,int value)   //set gpio is output
{
    gpio_direction_output(PI,value);
}


void read_data(void)
{
    temp = 0;
    gpio_out(TRIG,1);
    udelay(13);
    gpio_out(TRIG,0);
    while(!gpio_get_value(ECHO));
    while(gpio_get_value(ECHO)){
        temp++;
    }
    buf[0] = temp;
}


static int test_open(struct inode *inode, struct file *file)
{
	printk("open in kernel\n");
	return 0;
}


static ssize_t test_read(struct file *file, char* buffer,size_t size ,loff_t *off)
{
		int ret;
		read_data();
		ret = copy_to_user(buffer,buf,sizeof(buf));
		printk("%d",buf[0]);
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





static int test_release(struct inode *inode, struct file *file)
{
	printk("test release\n");
	return 0;
}

static struct file_operations HC_dev_fops={
	owner	:	THIS_MODULE,
	open	:	test_open,
	read	:	test_read,
	release	:	test_release,
};
static struct class *HC_class;

static int __init test_init(void)
{
	int ret;

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
	
	if( gpio_request( TRIG, DEVICE_NAME ) < 0 )	// request pin YELLOW 
	{
		printk( KERN_INFO "%s: %s unable to get TRIG gpio\n", DEVICE_NAME, __func__ );
		ret = -EBUSY;
		return(ret);
	}
	

	gpio_out(TRIG,0);
	gpio_direction_input(ECHO);


	return 0 ;
}

static void __exit test_exit(void)
{
	gpio_free(ECHO);
	gpio_free(TRIG);
	device_destroy(light_class,DEVICE_MAJOR);
	class_destroy(light_class);
	unregister_chrdev(DEVICE_MAJOR, DEVICE_NAME);
}
module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sr");
