TARGET_CURL=/media/clement/Clem/RPI/meteo/target_curl

PATH_CC=/media/clement/Clem/RPI/tools-master/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin
CC=$(PATH_CC)/arm-linux-gnueabihf-gcc

INC=-I$(TARGET_CURL)/include -I/media/clement/Clem/RPI/meteo/target_open_ssl/include -I/media/clement/Clem/RPI/meteo/target_open_ssl/include/openssl -I/media/clement/Clem/RPI/meteo/target-zlib/include
LIB=-L$(TARGET_CURL)/lib -L/media/clement/Clem/RPI/meteo/target_open_ssl/lib -L/media/clement/Clem/RPI/meteo/target-zlib/lib

all: simple_http_request simple_https_request test_meteo

simple_http_request: simple_http_request.c
	$(CC) $(INC) $(LIB) simple_http_request.c -o simple_http_request.exe -lcurl -lssl -lrt -lcrypto -ldl -lpthread

simple_https_request: simple_https_request.c
	$(CC) $(INC) $(LIB) simple_https_request.c -o simple_https_request.exe -lcurl -lssl -lrt -lcrypto -ldl -lpthread

test_meteo: test_meteo.c
	$(CC) $(INC) $(LIB) test_meteo.c -o test_meteo.exe -lcurl -lssl -lrt -lcrypto -ldl -lpthread

clean :
	rm -rf *.exe