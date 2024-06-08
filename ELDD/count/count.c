#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include "header.h"
int i;
static int __init count_entry(void){
	printk(KERN_INFO "Module initialized\n");
	printk(KERN_ALERT "Countdown started\n");
	for(i=0;i<100;i++){
	printk(KERN_ALERT "%d\n",count());
	}
	return 0;
}

static void __exit count_exit(void){
	printk(KERN_INFO "Module detached\n");
}
module_init(count_entry);
module_exit(count_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1");
MODULE_AUTHOR("ASHWIN");
