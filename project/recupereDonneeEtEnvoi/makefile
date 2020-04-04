TARGET_GPIO=/home/clement/Bureau/RPI/GPIO/wiringPi-36fb7f1/TARGET_WP
TARGET_FIREBASE=/media/clement/Clem/RPI/voicezy/pyrebase/library
TARGET_TEMPERATURE=/media/clement/Clem/RPI/voicezy/temperature/librairie

PATH_CC=/media/clement/Clem/RPI/tools-master/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin
CC=$(PATH_CC)/arm-linux-gnueabihf-gcc

INC=-I$(TARGET_GPIO)/include -I$(TARGET_FIREBASE) -I$(TARGET_TEMPERATURE)
LIB=-L$(TARGET_GPIO)/lib

all: recupereTemperatureEtEnvoi

recupereTemperatureEtEnvoi: recupereTemperatureEtEnvoi.c
	$(CC) $(INC) $(LIB) recupereTemperatureEtEnvoi.c -o recupereTemperatureEtEnvoi.exe -lwiringPi

clean :
	rm -rf getTemp*.exe