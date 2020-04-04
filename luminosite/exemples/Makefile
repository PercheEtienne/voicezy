DESTDIR=/home/etienne/Bureau/CCR/target_wp
PREFIX=
PATH_CC=/home/etienne/tools-master/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin

CC=$(PATH_CC)/arm-linux-gnueabihf-gcc

INC=-I$(DESTDIR)/include
LIB=-L$(DESTDIR)/lib

all:  bh1750

bh1750: testBH1750.c 
	$(CC) $(INC) $(LIB) testBH1750.c -o testBH1750.exe  -lwiringPi

clean : 
	rm -rf testBH1750.exe
