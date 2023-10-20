MODULE_NAME := hack
RESMAN_CORE_OBJS:=entry.o
RESMAN_GLUE_OBJS:=memory.o process.o
        obj-m := $(MODULE_NAME).o
	$(MODULE_NAME)-objs:=$(RESMAN_CORE_OBJS) $(RESMAN_GLUE_OBJS)
else
