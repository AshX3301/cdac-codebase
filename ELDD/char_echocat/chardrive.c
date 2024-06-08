#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/module.h>
#include<linux/cdev.h>
#include<linux/slab.h>
#include<linux/uaccess.h>
#include<linux/device.h>
#define DEVICE_NAME "chardev"
dev_t dev = 0;
static struct cdev chdev;
#define mem_size 100
uint8_t *kernel_buffer;
static struct class *dev_file;
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
static ssize_t device_read(struct file *fp,char *buff,size_t length,loff_t *offst){
	pr_info("Read operation invoked\n");
	if(copy_to_user(buff,kernel_buffer,mem_size)==0){
		pr_alert("Data Read error\n");
	else
		pr_info("Data read complete\n");

	return mem_size;
}
static ssize_t device_write(struct file *fp,const char *buff,size_t length,loff_t *offst){
	pr_info("Write operation invoked\n");
	if(copy_from_user(kernel_buffer,buff,length)==0){
		pr_alert("Data write error\n"|);
	else
		pr_info("Data write complete\n");
	return length;
}

static int __init dev_entry(void){
	pr_info("Char module initialized\n");
        if((alloc_chrdev_region(&dev,0,1,DEVICE_NAME))<0){
                pr_alert("Dynamic number allocation failed\n");
                return -1;
        }
        pr_info("MAJOR: %d MINOR: %d\n",MAJOR(dev),MINOR(dev));
        pr_info("Number allocation successful\n");
	if((dev_file = class_create(THIS_MODULE,"chardrivclass"))==NULL){
		pr_alert("cannot create class for  device\n");
		goto r_class;
	}
	if((device_create(dev_file,NULL,dev,NULL,"chardrivclass"))==NULL){
		pr_alert("cannot create device file\n");
		goto r_device;
	}
	else
		pr_info("Device file created dynamically\n");

	cdev_init(&chdev,&fops);
	if(cdev_add(&chdev,dev,1)<0){
	pr_alert("Cannot add device\n");
	return 1;
	}
	else
	pr_info("Device added\n");
	if((kernel_buffer = kmalloc(mem_size,GFP_KERNEL))==NULL){
		pr_alert("Error allocating memory to kernel buffer\n");
	}
	strcpy(kernel_buffer,"Hello from kernel\n");
	return 0;
r_device:
	class_destroy(dev_file);
r_class:
	unregister_chrdev_region(dev,1);
	return -1;
}
static void __exit dev_exit(void){
	kfree(kernel_buffer);
	kernel_buffer = NULL;
	pr_info("Dynamic number module detached\n");
	cdev_del(&chdev);
	unregister_chrdev_region(dev,1);
}

module_init(dev_entry);
module_exit(dev_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1");
MODULE_AUTHOR("ASHWIN");
