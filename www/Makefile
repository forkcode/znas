CC=arm-mv5sft-linux-gnueabi-gcc
INCLUDE=-I./
LIB=-L./ 
LDFLAGS=-lcgic

ALL:
	$(CC) $(INCLUDE) $(LIB) -o index.cgi *.c $(LDFLAGS)
	scp index.cgi admin@10.18.13.10:/www

clean:
	rm -f *.cgi
