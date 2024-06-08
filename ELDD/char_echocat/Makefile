obj-m += dyn.o

kerneldir = /lib/modules/$(shell uname -r)/build

all:
	make -C $(kerneldir) M=$(PWD) modules

clean:
	make -C $(kerneldir) M=$(PWD) clean
