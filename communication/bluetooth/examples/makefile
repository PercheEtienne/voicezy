TARGET_BLUETOOTH=/media/clement/Clem/RPI/target_bluetooth/usr/local

PATH_CC=/media/clement/Clem/RPI/tools-master/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin
CC=$(PATH_CC)/arm-linux-gnueabihf-gcc

INC=-I$(TARGET_BLUETOOTH)/include
LIB=-L$(TARGET_BLUETOOTH)/lib

all: scan_device connect_to_arduino light_leds envoi_forme

scan_device: scan_device.c
	$(CC) $(INC) $(LIB) scan_device.c -o scan_device.exe -lbluetooth

connect_to_arduino: connect_to_arduino.c
	$(CC) $(INC) $(LIB) connect_to_arduino.c -o connect_to_arduino.exe -lbluetooth

light_leds: light_leds.c
	$(CC) $(INC) $(LIB) light_leds.c -o light_leds.exe -lbluetooth

envoi_forme: envoi_forme.c
	$(CC) $(INC) $(LIB) envoi_forme.c -o envoi_forme.exe -lbluetooth

clean :
	rm -rf *.exe