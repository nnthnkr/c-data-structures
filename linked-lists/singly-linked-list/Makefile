CXX = gcc
CXX_FLAGS = -Wall -g

TARGET = main

# Source and Objects
SRCS = LL.c main.c

# include flags
ifeq ($(MEDIUM_Q), 1)
	SRCS += medium_q.c
	SRCS += stack.c
	CXX_FLAGS += -Dmedium_q
endif

OBJS = $(SRCS:.c=.o)

all: $(TARGET)


$(TARGET): $(OBJS)
	$(CXX) $(CXX_FLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CXX) $(CXX_FLAGS) -c $< -o $@


clean:
	# rm -f $(OBJS) $(TARGET)
	rm -f *.o $(TARGET)
