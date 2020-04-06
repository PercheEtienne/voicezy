TARGET_CURL=/media/clement/Clem/RPI/meteo/target_curl
TARGET_METEO=/media/clement/Clem/RPI/voicezy/meteo/library
TARGET_MY_BLUETOOTH=/media/clement/Clem/RPI/voicezy/communication/bluetooth/library
TARGET_BLUETOOTH=/media/clement/Clem/RPI/target_bluetooth/usr/local
TARGET_FIREBASE=/media/clement/Clem/RPI/voicezy/pyrebase/library


PATH_CC=/media/clement/Clem/RPI/tools-master/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin
CC=$(PATH_CC)/arm-linux-gnueabihf-gcc

INC=-I$(TARGET_CURL)/include -I/media/clement/Clem/RPI/meteo/target_open_ssl/include -I/media/clement/Clem/RPI/meteo/target_open_ssl/include/openssl -I/media/clement/Clem/RPI/meteo/target-zlib/include -I$(TARGET_METEO) -I$(TARGET_BLUETOOTH)/include -I$(TARGET_MY_BLUETOOTH) -I$(TARGET_FIREBASE)
LIB=-L$(TARGET_CURL)/lib -L/media/clement/Clem/RPI/meteo/target_open_ssl/lib -L/media/clement/Clem/RPI/meteo/target-zlib/lib -L$(TARGET_BLUETOOTH)/lib

all: afficheMeteoMatrice

afficheMeteoMatrice: afficheMeteoMatrice.c
	$(CC) $(INC) $(LIB) afficheMeteoMatrice.c -o afficheMeteoMatrice.exe -lcurl -lssl -lrt -lcrypto -ldl -lpthread -lbluetooth

clean :
	rm -rf *.exe