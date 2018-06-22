CC = gcc
CFLAGS = -w
TARGET = hw3_exe

all : $(TARGET)

$(TARGET) : buffer.o main.o prod_consum.o
	$(CC) $(CFLAGS) buffer.o main.o prod_consum.o -o $(TARGET) -l pthread -lrt
buffer.o : buffer.c
	$(CC) $(CFLAGS) -c buffer.c -l pthread -lrt
main.o : main.c
	$(CC) $(CFLAGS) -c main.c -l pthread -lrt
prod_consum.o : prod_consum.c
	$(CC) $(CFLAGS) -c prod_consum.c -l pthread -lrt

clean :
	rm buffer.o main.o prod_consum.o $(TARGET)
