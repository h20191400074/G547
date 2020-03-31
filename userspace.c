/*
 *  ioctl.c - the process to use ioctl's to control the kernel module
 *
 *  Until now we could have used cat for input and output.  But now
 *  we need to do ioctl's, which require writing our own process.
 */

/*
 * device specifics, such as ioctl numbers and the
 * major device file.
 */
#include "adc8.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <fcntl.h>              /* open */
#include <unistd.h>             /* exit */
#include <sys/ioctl.h>          /* ioctl */


/*
 * Functions for the ioctl calls
 */
uint16_t buffer;

int ioctl_set_alignment(int file_desc, char *message)
{
    int ret_val;
    ret_val = ioctl(file_desc, IOCTL_SET_ALIGNMENT, message);

    if (ret_val < 0) {
        printf("ioctl_set_msg failed:%d\n", ret_val);
        exit(-1);
    }
    return 0;
}

int ioctl_set_channel(int file_desc, char *message)
{
    int ret_val;
    ret_val = ioctl(file_desc, IOCTL_SELECT_CHANNEL, message);

    if (ret_val < 0) {
        printf("ioctl_get_msg failed:%d\n", ret_val);
        exit(-1);
    }
    return 0;
}


/*
 * Main - Call the ioctl functions
 */
int main()
{
    int count;
    int file_desc, ret_val;
    char *msg = "Message passed by ioctl\n";

    file_desc = open(DEVICE_FILE_NAME, 0);
    if (file_desc < 0) {
        printf("Can't open device file: %s\n", DEVICE_FILE_NAME);
        exit(-1);
    }


    ioctl_set_alignment(file_desc, "2");
    ioctl_set_channel(file_desc, "5" );
    count = read(file_desc, &buffer, sizeof(buffer));
    printf("10 bit adc value: \n");
    printf("%u\n", buffer);

    close(file_desc);
    return 0;
}
