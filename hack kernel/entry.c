#include <linux/module.h>
#include <linux/tty.h>
#include <linux/miscdevice.h>
#include "comm.h"
#include "memory.h"
#include "process.h"
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/random.h>

#define DEVICE_NAME_LEN 20 // 设备名称的最大长度

static char random_device_name[DEVICE_NAME_LEN]; // 存储随机设备节点名称的缓冲区
static struct miscdevice my_device;

static int generate_random_device_name(void) {
    // 生成随机设备节点名称
    int i;
    get_random_bytes(random_device_name, DEVICE_NAME_LEN);

    // 转换为有效的设备节点字符
    for (i = 0; i < DEVICE_NAME_LEN; i++) {
        random_device_name[i] = 'a' + (random_device_name[i] % 26);
    }
    return 0;
}

static int __init my_init(void) {
    generate_random_device_name(); // 生成随机设备节点名称

    my_device.minor = MISC_DYNAMIC_MINOR;
    my_device.name = random_device_name;
    my_device.fops = &dispatch_functions; // 使用您的文件操作函数

    int ret = misc_register(&my_device);
    if (ret != 0) {
        printk(KERN_ERR "Failed to register device\n");
        return ret;
    }

    printk(KERN_INFO "Device registered with random name: %s\n", random_device_name);
    return 0;
}

static void __exit my_exit(void) {
    misc_deregister(&my_device);
    printk(KERN_INFO "Device unregistered\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_DESCRIPTION("Module for kernel.");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("LingXiZi");
