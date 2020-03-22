TARGET_GPIO=/home/clement/Bureau/RPI/GPIO/wiringPi-36fb7f1/TARGET_WP
LIB_MATRIX=/home/clement/Bureau/RPI/voicezy/led_matrix/librairie
LIB_BUTTON=/home/clement/Bureau/RPI/voicezy/button/librairie

PATH_CC=/home/clement/Bureau/RPI/tools-master/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin
CC=$(PATH_CC)/arm-linux-gnueabihf-gcc

INC=-I$(TARGET_GPIO)/include -I$(LIB_MATRIX) -I$(LIB_BUTTON)
LIB=-L$(TARGET_GPIO)/lib

all: voicezy_v1

voicezy_v1: voicezy_v1.c
	$(CC) $(INC) $(LIB) voicezy_v1.c -o voicezy_v1.exe -lwiringPi

clean :
	rm -rf voicezy*.exe