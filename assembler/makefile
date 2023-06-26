CC = gcc
CFLAGS = -W -Wall
TARGET = a.out
OBJS = main.o file.o asm.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJS)
