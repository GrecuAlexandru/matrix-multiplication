CC = gcc
CFLAGS = -Wall -Wextra
SRCS = simple_matmul.c matrix_utils.c
OBJS = $(SRCS:.c=.o)
TARGET = coco

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
