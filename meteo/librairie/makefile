TARGET_GPIO=/usr/local

PATH_CC=/home/clement/Bureau/RPI/tools-master/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin
CC=$(PATH_CC)/arm-linux-gnueabihf-gcc

INC=-I$(TARGET_GPIO)/include
LIB=-L$(TARGET_GPIO)/lib

all: meteo

meteo: meteo.c
	$(CC) $(INC) $(LIB) meteo.c -o meteo.exe -lcurl -lrt -lpthread

clean :
	rm -rf meteo*.exe