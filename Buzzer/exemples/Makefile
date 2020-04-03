DESTDIR=/home/etienne/Bureau/CCR/target_wp
PREFIX=
PATH_CC=/home/etienne/tools-master/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin
CC=$(PATH_CC)/arm-linux-gnueabihf-gcc

INC=-I$(DESTDIR)/include
LIB=-L$(DESTDIR)/lib

all: mario

mario: mario.c
	$(CC) $(INC) $(LIB) mario.c -o mario.exe  -lwiringPi

clean :
	rm -rf  mario.exe