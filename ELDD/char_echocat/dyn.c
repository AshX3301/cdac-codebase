#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/module.h>
#include<linux/cdev.h>
#define DEVICE_NAME "chardev"
dev_t dev = 0;
static struct cdev chdev;
#define mem_size 100
static char msg[mem_size];

static int device_open(struct inode *,struct file *);
static int device_release(struct inode *,struct file *);
static ssize_t device_read(struct file *,char *,size_t,loff_t *);
static ssize_t device_write(struct file *,const char *,size_t,loff_t *);
static struct file_operations fops = {
        .owner = THIS_MODULE,
        .read = device_read,
        .write = device_write,
        .open = device_open,
        .release = device_release
};

static int device_open(struct inode *inode,struct file *file){
	pr_info("Device Opened\n");
	return 0;
}
static int device_release(struct inode *inode,struct file *file){
	pr_info("Device Released\n");
	return 0;
}
static ssize_t device_read(struct file *fp,char *msg,size_t length,loff_t *offst){
	pr_info("Read operation invoked\n");
	return 0;
}
static ssize_t device_write(struct file *fp,const char *msg,size_t length,loff_t *offst){
	pr_info("Write operation invoked\n");
	return 0;
}

static int __init dev_entry(void){
	pr_info("Char module initialized\n");
        if((alloc_chrdev_region(&dev,0,1,DEVICE_NAME))<0){
                pr_alert("Dynamic number allocation failed\n");
                return -1;
        }
        pr_info("MAJOR: %d MINOR: %d\n",MAJOR(dev),MINOR(dev));
        pr_info("Number allocation successful\n");

	cdev_init(&chdev,&fops);
	if(cdev_add(&chdev,dev,1)<0){
	pr_alert("Cannot add device\n");
	return 1;
	}
	else
	pr_info("Device added\n");

	return 0;
}
static void __exit dev_exit(void){
	pr_info("Dynamic number module detached\n");
	cdev_del(&chdev);
	unregister_chrdev_region(dev,1);
}

module_init(dev_entry);
module_exit(dev_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1");
MODULE_AUTHOR("ASHWIN");
