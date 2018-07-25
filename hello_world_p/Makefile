ifneq ($(KERNELRELEASE),)
    	# KERNELRELEASE is empty when first using make.
	# Therefore, jump to else in first case 
	obj-m := hello_world_p.o

else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)

modules:
	# Second using make, and KERNELRELEASE was defined.
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions

.PHONY: modules clean
             
endif

