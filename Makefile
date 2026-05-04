CC = gcc
CFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

infoscreen: main.c
	$(CC) $(CFLAGS) -o infoscreen main.c

clean:
	rm infoscreen