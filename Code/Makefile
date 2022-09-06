BINARY = ./bin/proyecto
CODEDIRS = ./lib
INCDIRS = ./include/

CC = clang++

DEPFLAGS = -MP -MD

CXXFLAGS = -Wall -Wextra -Wpedantic -Wformat 
CFLAGS =  $(CXXFLAGS) $(foreach D, $(INCDIRS),-I$(D)) $(DEPFLAGS) -O3

CFILES = $(foreach D,$(CODEDIRS),$(wildcard $(D)/*.cpp))

OBJECTS = $(patsubst ./lib/%.cpp,./obj/%.o,$(CFILES))

DEPFILES = $(patsubst ./lib/%.cpp,./obj/%.d,$(CFILES))


all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) $(CFLAGS) -fuse-ld=mold -o $@ $^

obj:
	@mkdir -p obj

obj/%.o: lib/%.cpp | obj
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf $(BINARY) $(OBJECTS) $(DEPFILES)

-include $(DEPFILES)
