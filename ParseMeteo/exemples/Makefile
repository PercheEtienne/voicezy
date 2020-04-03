PATH_CC=/home/etienne/tools-master/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin
CC=$(PATH_CC)/arm-linux-gnueabihf-gcc

all: meteorpi

meteorpi: recupMeteo.c
	$(CC) recupMeteo.c -o recupMeteoRPI.exe
	gcc recupMeteo.c -o recupMeteoPC.exe

clean :
	rm -rf recupMeteoRPI.exe recupMeteoPC.exe
