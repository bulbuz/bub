OBJS = src/*.cpp
CC = g++
COMPILER_FLAGS = -w -std=c++17
LINKER_FLAGS = -lSDL2 -lSDL2_image
INCLUDE_FLAGS = -Iinclude
OBJ_NAME = Main

all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(INCLUDE_FLAGS) -o bin/debug/$(OBJ_NAME)
