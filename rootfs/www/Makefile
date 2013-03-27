CC=arm-mv5sft-linux-gnueabi-gcc
INCLUDE=-I./
LIB=-L./ 
LDFLAGS=-lcgic

ALL:
	$(CC) $(INCLUDE) $(LIB) -o index.cgi index.cgi.c $(LDFLAGS)


clean:
	rm -f *.cgi
