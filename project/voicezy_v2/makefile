TARGET_GPIO=/home/clement/Bureau/RPI/GPIO/wiringPi-36fb7f1/TARGET_WP
LIB_MATRIX=/media/clement/Clem/RPI/voicezy/led_matrix/librairie
LIB_BUTTON=/media/clement/Clem/RPI/voicezy/button/librairie
TARGET_CURL=/media/clement/Clem/RPI/meteo/target_curl
TARGET_METEO=/media/clement/Clem/RPI/voicezy/meteo/library
TARGET_MY_BLUETOOTH=/media/clement/Clem/RPI/voicezy/communication/bluetooth/library
TARGET_BLUETOOTH=/media/clement/Clem/RPI/target_bluetooth/usr/local
TARGET_REC_VOCALE=/media/clement/Clem/RPI/voicezy/reconnaissance_vocale/library
TARGET_TEMPERATURE=/media/clement/Clem/RPI/voicezy/temperature/librairie
TARGET_LUMINOSITY=/media/clement/Clem/RPI/voicezy/luminosite/librairie
TARGET_BUZZER=/media/clement/Clem/RPI/voicezy/buzzer/librairie
TARGET_FIREBASE=/media/clement/Clem/RPI/voicezy/pyrebase/library

PATH_CC=/media/clement/Clem/RPI/tools-master/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin
CC=$(PATH_CC)/arm-linux-gnueabihf-gcc

INC=-I$(TARGET_GPIO)/include -I$(LIB_MATRIX) -I$(LIB_BUTTON) -I$(TARGET_CURL)/include -I/media/clement/Clem/RPI/meteo/target_open_ssl/include -I/media/clement/Clem/RPI/meteo/target_open_ssl/include/openssl -I/media/clement/Clem/RPI/meteo/target-zlib/include -I$(TARGET_METEO) -I$(TARGET_BLUETOOTH)/include -I$(TARGET_MY_BLUETOOTH) -I$(TARGET_REC_VOCALE) -I$(TARGET_TEMPERATURE) -I$(TARGET_LUMINOSITY) -I$(TARGET_BUZZER) -I$(TARGET_FIREBASE)
LIB=-L$(TARGET_GPIO)/lib -L$(TARGET_CURL)/lib -L/media/clement/Clem/RPI/meteo/target_open_ssl/lib -L/media/clement/Clem/RPI/meteo/target-zlib/lib -L$(TARGET_BLUETOOTH)/lib

all: voicezy_v2

voicezy_v2: voicezy_v2.c
	$(CC) $(INC) $(LIB) voicezy_v2.c -o voicezy_v2.exe -lwiringPi -lcurl -lssl -lrt -lcrypto -ldl -lpthread -lbluetooth

clean :
	rm -rf voicezy*.exe