PATH_CC=/media/clement/Clem/RPI/tools-master/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin
CC=$(PATH_CC)/arm-linux-gnueabihf-gcc

all: sendTemperatureToFirebase

sendTemperatureToFirebase: sendTemperatureToFirebase.c
	$(CC) sendTemperatureToFirebase.c -o sendTemperatureToFirebase.exe

clean :
	rm -rf *.exe