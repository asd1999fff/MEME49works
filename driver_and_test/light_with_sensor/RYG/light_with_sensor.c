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




#define RED (14)
#define YELLOW (23)
#define GREEN (24)


#define DEVICE_MAJOR 205
#define DEVICE_NAME "light"

#define BUF_LEN 2

typedef unsigned char U8;
unsigned char buf[BUF_LEN];



void gpio_out(int PI ,int value)   //set gpio is output
{
    gpio_direction_output(PI,value);
}


void read_data(void)
{
	switch(buf[0]){
	case 0:
		gpio_out(GREEN,1);
		gpio_out(YELLOW,0);
		gpio_out(RED,0);
		break;
	case 1:
		gpio_out(GREEN,0);
		gpio_out(YELLOW,1);
		gpio_out(RED,0);
		break;
	case 2:
		gpio_out(GREEN,0);
		gpio_out(YELLOW,0);
		gpio_out(RED,1);
		break;
	default:
		printk("error number");
		break;
	}
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

static ssize_t test_write(struct file *file, const char *buffer, size_t size, loff_t *off)
{
	get_user(buf[0],buffer);
	buf[0] -= 48;
	printk("%d",buf[0]);
	read_data();

		return size;
}




static int test_release(struct inode *inode, struct file *file)
{
	printk("test release\n");
	return 0;
}

static struct file_operations light_dev_fops={
	owner	:	THIS_MODULE,
	open	:	test_open,
	read	:	test_read,
	write	:	test_write,
	release	:	test_release,
};
static struct class *light_class;

static int __init test_init(void)
{
	int ret;

	ret =register_chrdev(DEVICE_MAJOR, DEVICE_NAME, &light_dev_fops);
	if (ret < 0) {
		printk(KERN_INFO "%s: registering device %s with major %d failed with %d\n",
		__func__, DEVICE_NAME, DEVICE_MAJOR, DEVICE_MAJOR );
		return(ret);
		}
	printk("test driver register success!\n");

	light_class = class_create(THIS_MODULE, "light");
		if(IS_ERR(light_class))
		{
			printk(KERN_WARNING "CANT MAKE NODE %d\n",DEVICE_MAJOR);
				return PTR_ERR(light_class);
		}

		device_create(light_class, NULL, MKDEV(DEVICE_MAJOR, 0), NULL, DEVICE_NAME);

		printk("test driver make node success!\n");

	
	if( gpio_request( RED, DEVICE_NAME ) < 0 )	// request pin RED 
	{
		printk( KERN_INFO "%s: %s unable to get TRIG gpio\n", DEVICE_NAME, __func__ );
		ret = -EBUSY;
		return(ret);
	}
	
	if( gpio_request( YELLOW, DEVICE_NAME ) < 0 )	// request pin YELLOW 
	{
		printk( KERN_INFO "%s: %s unable to get TRIG gpio\n", DEVICE_NAME, __func__ );
		ret = -EBUSY;
		return(ret);
	}
	
	if( gpio_request( GREEN, DEVICE_NAME ) < 0 )	// request pin GREEN 
	{
		printk( KERN_INFO "%s: %s unable to get TRIG gpio\n", DEVICE_NAME, __func__ );
		ret = -EBUSY;
		return(ret);
	}


	gpio_out(YELLOW,0);
	gpio_out(RED,0);
	gpio_out(GREEN,0);


	return 0 ;
}

static void __exit test_exit(void)
{
	gpio_free(RED);
	gpio_free(YELLOW);
	gpio_free(GREEN);
	device_destroy(light_class,DEVICE_MAJOR);
	class_destroy(light_class);
	unregister_chrdev(DEVICE_MAJOR, DEVICE_NAME);
}
module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sr");
