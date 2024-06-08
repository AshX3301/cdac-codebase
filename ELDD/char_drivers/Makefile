obj-m += chardrive.o

kerneldir = /lib/modules/$(shell uname -r)/build

#cross_comp = ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf-

all:
	make -C $(kerneldir) M=$(PWD) modules

clean:
	make -C $(kerneldir) M=$(PWD) clean
