TARGET_CURL=/media/clement/Clem/RPI/meteo/target_curl

PATH_CC=/media/clement/Clem/RPI/tools-master/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin
CC=$(PATH_CC)/arm-linux-gnueabihf-gcc

INC=-I$(TARGET_CURL)/include -I/media/clement/Clem/RPI/meteo/target_open_ssl/include -I/media/clement/Clem/RPI/meteo/target_open_ssl/include/openssl -I/media/clement/Clem/RPI/meteo/target-zlib/include
LIB=-L$(TARGET_CURL)/lib -L/media/clement/Clem/RPI/meteo/target_open_ssl/lib -L/media/clement/Clem/RPI/meteo/target-zlib/lib

all: recupMeteo

recupMeteo : recupMeteo.c
	$(CC) $(INC) $(LIB) recupMeteo.c -o recupMeteo.exe -lcurl -lssl -lrt -lcrypto -ldl -lpthread

clean :
	rm -rf *.exe