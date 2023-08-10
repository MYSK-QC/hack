MODULE_NAME := jdtygd
RESMAN_CORE_OBJS:=
RESMAN_GLUE_OBJS:=
ifneq ($(KERNELRELEASE),)
	$(MODULE_NAME)-objs:=$(RESMAN_CORE_OBJS) $(RESMAN_GLUE_OBJS)
		obj-m := wanbai.o
	wanbai-objs := memory.o process.o entry.o
else
	KDIR := /root/kernel_realme_sm8350/out
all:
	make -C $(KDIR) M=$(PWD) modules
	rm -rf *.mod .*cmd *.o *.mod.c .tmp_versions *.order *symvers *Module.markers .*.d
	llvm-strip --strip-debug wanbai.ko
clean:
	rm -rf *.mod .*cmd *.o *.mod.c .tmp_versions *.order *symvers *Module.markers .*.d
endif
