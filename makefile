# Compiler and flags
CC = g++
CFLAGS = -Wall -Wextra -g

# Output executable
TARGET = main.exe

# Source files
SRCS = main.c \
       logic/battle.c \
       logic/menu.c \
       logic/utility.c \
       visual/enemyVisual.c \
       visual/playerVisual.c \
       visual/UIVisual.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Link all object files
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile each .c into .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files (works in cmd.exe)
clean:
	del /Q $(OBJS) $(TARGET) 2>nul
