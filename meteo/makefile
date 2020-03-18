TARGET_GPIO=/usr/local

PATH_CC=/home/clement/Bureau/RPI/tools-master/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin
CC=$(PATH_CC)/arm-linux-gnueabihf-gcc

INC=-I$(TARGET_GPIO)/include
LIB=-L$(TARGET_GPIO)/lib

all: simple_http_request test_api

simple_http_request: simple_http_request.c
	$(CC) $(INC) $(LIB) simple_http_request.c -o simple_http_request.exe -lcurl -lrt -lpthread

test_api: test_api.c
	$(CC) $(INC) $(LIB) test_api.c -o test_api.exe -lcurl -lrt -lpthread

clean :
	rm -rf *.exe