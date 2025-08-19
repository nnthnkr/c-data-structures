CXX = gcc
CXX_FLAGS = -Wall -g

TARGET = main

# Source and Objects
SRCS = LL.c main.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXX_FLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
