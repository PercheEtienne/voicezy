TARGET_GPIO=/home/clement/Bureau/RPI/GPIO/wiringPi-36fb7f1/TARGET_WP


PATH_CC=/home/clement/Bureau/RPI/tools-master/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin
CC=$(PATH_CC)/arm-linux-gnueabihf-gcc

INC=-I$(TARGET_GPIO)/include
LIB=-L$(TARGET_GPIO)/lib

all: matrix

matrix: matrix_led.c
	$(CC) $(INC) $(LIB) matrix_led.c -o matrix_led.exe -lwiringPi

clean :
	rm -rf matrix_led.exe