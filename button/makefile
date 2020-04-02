TARGET_GPIO=/home/clement/Bureau/RPI/GPIO/wiringPi-36fb7f1/TARGET_WP

PATH_CC=/media/clement/Clem/RPI/tools-master/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin
CC=$(PATH_CC)/arm-linux-gnueabihf-gcc

INC=-I$(TARGET_GPIO)/include
LIB=-L$(TARGET_GPIO)/lib

all: button

button: button_v1.c button_v3.c
	$(CC) $(INC) $(LIB) button_v1.c -o button_v1.exe -lwiringPi
	$(CC) $(INC) $(LIB) button_v2.c -o button_v2.exe -lwiringPi
	$(CC) $(INC) $(LIB) button_v3.c -o button_v3.exe -lwiringPi -pthread

clean :
	rm -rf button*.exe