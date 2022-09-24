BINARY = ./bin/proyecto
CODEDIRS = ./lib
INCDIRS = ./include/

CC = clang++
OS = $(shell uname)

FOLDERS_COMMAND = mkdir -p obj bin include lib

ifeq ($(OS),Linux)
	rm_C = rm -rf
else
	rm_C = del
	FOLDERS_COMMAND = "echo"
endif

DEPFLAGS = -MP -MD

CXXFLAGS = -Wall -Wextra -Wpedantic -Wformat -std=c++17
CFLAGS =  $(CXXFLAGS) $(foreach D, $(INCDIRS),-I$(D)) $(DEPFLAGS) -O3

CFILES = $(foreach D,$(CODEDIRS),$(wildcard $(D)/*.cpp))

OBJECTS = $(patsubst ./lib/%.cpp,./obj/%.o,$(CFILES))

DEPFILES = $(patsubst ./lib/%.cpp,./obj/%.d,$(CFILES))

all: $(BINARY)

run: $(BINARY)
	$(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) $(CFLAGS) -fuse-ld=mold -o $@ $^

folders:
	@$(FOLDERS_COMMAND)

obj/%.o: lib/%.cpp | folders
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	$(rm_C) $(BINARY) $(OBJECTS) $(DEPFILES)

-include $(DEPFILES)
