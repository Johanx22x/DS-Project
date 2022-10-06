BINARY = ./bin/proyecto
CODEDIRS = ./lib
INCDIRS = ./include/
COMMANDS_DIR = $(CODEDIRS)/menus

CC = clang++

# NOTE: MacOS not comptemplated
ifeq ($(OS),Windows_NT)
	rm_C = del bin\* obj\*
	SYSLIB = dll
else
	FOLDERS_COMMAND = mkdir -p obj bin include lib
	LINKFLAGS = -fuse-ld=mold
	rm_C = rm -rf $(BINARY) $(OBJECTS) $(DEPFILES) ./bin/*
	SYSLIB = so
endif

DEPFLAGS = -MP -MD

CXXFLAGS = -Wall -Wextra -Wpedantic -Wformat -std=c++17
CFLAGS =  $(CXXFLAGS) $(foreach D, $(INCDIRS),-I$(D)) -O3

CFILES = $(foreach D,$(CODEDIRS),$(wildcard $(D)/*.cpp))

OBJECTS = $(patsubst ./lib/%.cpp,./obj/%.o,$(CFILES))

DEPFILES = $(patsubst ./lib/%.cpp,./obj/%.d,$(CFILES))

COMMAND_SOURCE = $(wildcard $(COMMANDS_DIR)/*.cpp)
COMMAND_LIB = $(patsubst ./lib/menus/%.cpp,bin/%.$(SYSLIB),$(COMMAND_SOURCE))

all: $(BINARY)

run: $(BINARY)
	$(BINARY)

menu: $(COMMAND_LIB)

ifeq ($(OS),Windows_NT)
bin/%.dll: lib/menus/%.cpp $(OBJECTS)
	$(CC) $(CFLAGS) -shared -fPIC -o $@ $^
else
bin/%.so: lib/menus/%.cpp $(OBJECTS)
	$(CC) $(CFLAGS) -shared -fPIC -o $@ $^
endif

$(BINARY): $(OBJECTS)
	$(CC) $(LINKFLAGS) $(CFLAGS) -o $@ $^

folders:
	@$(FOLDERS_COMMAND)

obj/%.o: lib/%.cpp | folders
	$(CC) $(CFLAGS) -fPIC $(DEPFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	$(rm_C)

-include $(DEPFILES)
