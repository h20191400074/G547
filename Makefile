obj-m +=main_1.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	rm -rf *.o *.mod *.symvers *.mod.c *.mod.o *.order
