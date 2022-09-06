BINARY = ./bin/proyecto
CODEDIRS = ./lib
INCDIRS = ./include/

CC = clang++

DEPFLAGS = -MP -MD

CFLAGS = $(foreach D, $(INCDIRS),-I$(D)) $(DEPFLAGS) -o3

CFILES = $(foreach D,$(CODEDIRS),$(wildcard $(D)/*.cpp))

OBJECTS = $(patsubst %.cpp,%.o,$(CFILES))
DEPFILES = $(patsubst %.cpp,%.d,$(CFILES))

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf $(BINARY) $(OBJECTS) $(DEPFILES)

-include $(DEPFILES)
