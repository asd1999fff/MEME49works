4412_KERNEL_DIR = /lib/modules/$(shell uname -r)/build
ifneq ($(KERNELRELEASE),)
	obj-m := red_yellow_green.o
else
	KERNELDIR ?= $(4412_KERNEL_DIR)
	
	PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
clean:
	rm -f *.ko *.o *.bak *.mod.*
endif 
