TARGET_GPIO=/home/clement/Bureau/RPI/GPIO/wiringPi-36fb7f1/TARGET_WP

PATH_CC=/home/clement/Bureau/RPI/tools-master/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin
CC=$(PATH_CC)/arm-linux-gnueabihf-gcc

INC=-I$(TARGET_GPIO)/include
LIB=-L$(TARGET_GPIO)/lib

all: button

button: button.c
	$(CC) $(INC) $(LIB) button.c -o button.exe -lwiringPi

clean :
	rm -rf button*.exe