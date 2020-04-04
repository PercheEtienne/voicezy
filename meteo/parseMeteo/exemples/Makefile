PATH_CC=/media/clement/Clem/RPI/tools-master/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin
CC=$(PATH_CC)/arm-linux-gnueabihf-gcc

all: meteorpi

meteorpi: recupMeteo.c
	$(CC) recupMeteo.c -o recupMeteo.exe

clean :
	rm -rf *.exe
