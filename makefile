CC = gcc
CFLAGS = -std=c99
TARGET = runsim
OBJS = runsim.o
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
runsim.o: runsim.c
	$(CC) -c runsim.c

clean:
	/bin/rm -f *.o $(TARGET)