#ifndef CHARDEV_H
#define CHARDEV_H

#include <linux/ioctl.h>

#define MAJOR_NUM 100

#define IOCTL_SET_ALIGNMENT _IOW(MAJOR_NUM, 0, char *)

#define IOCTL_SELECT_CHANNEL _IOW(MAJOR_NUM, 1, char *)

#define DEVICE_FILE_NAME "/dev/adc8"

#endif
