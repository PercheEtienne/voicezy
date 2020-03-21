TARGET_CURL=/home/clement/Bureau/RPI/meteo/target_curl

PATH_CC=/home/clement/Bureau/RPI/tools-master/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin
CC=$(PATH_CC)/arm-linux-gnueabihf-gcc

INC=-I$(TARGET_CURL)/include -I/home/clement/Bureau/RPI/meteo/target_open_ssl/include -I/home/clement/Bureau/RPI/meteo/target_open_ssl/include/openssl -I/home/clement/Bureau/RPI/meteo/target-zlib/include
LIB=-L$(TARGET_CURL)/lib -L/home/clement/Bureau/RPI/meteo/target_open_ssl/lib -L/home/clement/Bureau/RPI/meteo/target-zlib/lib

all: simple_http_request test_api

simple_http_request: simple_http_request.c
	$(CC) $(INC) $(LIB) simple_http_request.c -o simple_http_request.exe -lcurl -lssl -lrt -lcrypto -ldl -lpthread

test_api: test_api.c
	$(CC) $(INC) $(LIB) test_api.c -o test_api.exe -lcurl -lssl -lrt -lcrypto -ldl -lpthread

clean :
	rm -rf *.exe