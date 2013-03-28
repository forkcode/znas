CC=arm-mv5sft-linux-gnueabi-gcc
INCLUDE=-I./
LIB=-L./ 
LDFLAGS=-lcgic

ALL:
	$(CC) $(INCLUDE) $(LIB) -o index.cgi *.c $(LDFLAGS)
	scp index.cgi admin@192.168.1.11:/www

clean:
	rm -f *.cgi
