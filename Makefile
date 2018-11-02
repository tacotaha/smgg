CC=gcc
CFLAGS=-Wall -pedantic
OBJ=main.o mediagen.o mediagen
LFLAGS=`MagickWand-config --cflags --ldflags --libs`

all: mediagen 

mediagen: mediagen.o main.o
	$(CC) $(CFLAGS) mediagen.o main.o -o mediagen $(LFLAGS)

main.o: Main.c
	$(CC) $(CFLAGS) -c Main.c -o main.o $(LFAGS)

mediagen.o: MediaGen.h MediaGen.c
	$(CC) $(CFLAGS) -c MediaGen.c -o mediagen.o $(LFLAGS)

clean:
	rm -f $(OBJ) *~
