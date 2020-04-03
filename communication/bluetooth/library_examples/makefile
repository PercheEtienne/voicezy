TARGET_BLUETOOTH=/media/clement/Clem/RPI/target_bluetooth/usr/local

PATH_CC=/media/clement/Clem/RPI/tools-master/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin
CC=$(PATH_CC)/arm-linux-gnueabihf-gcc

INC=-I$(TARGET_BLUETOOTH)/include
LIB=-L$(TARGET_BLUETOOTH)/lib

all: envoi_forme

envoi_forme: envoi_forme.c
	$(CC) $(INC) $(LIB) envoi_forme.c -o envoi_forme.exe -lbluetooth

clean :
	rm -rf *.exe