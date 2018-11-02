CC=gcc
CFLAGS=-Wall -pedantic
OBJ=main.o mediagen.o smgg 
LFLAGS=`MagickWand-config --cflags --ldflags --libs`

all: smgg 

smgg: smgg.o main.o
	$(CC) $(CFLAGS) smgg.o main.o -o smgg $(LFLAGS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o $(LFAGS)

smgg.o: smgg.h smgg.c
	$(CC) $(CFLAGS) -c smgg.c -o smgg.o $(LFLAGS)

clean:
	rm -f $(OBJ) *~
