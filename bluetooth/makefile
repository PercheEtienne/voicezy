TARGET_GPIO=/media/clement/Clem/RPI/target_bluetooth/usr/local

PATH_CC=/media/clement/Clem/RPI/tools-master/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin
CC=$(PATH_CC)/arm-linux-gnueabihf-gcc

INC=-I$(TARGET_GPIO)/include
LIB=-L$(TARGET_GPIO)/lib

all: test

test: test.c
	$(CC) $(INC) $(LIB) test.c -o test.exe -lbluetooth

clean :
	rm -rf button*.exe