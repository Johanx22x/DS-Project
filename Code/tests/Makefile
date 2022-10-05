TESTS = $(wildcard test_*)
OUT = $(patsubst test_%.cpp,test_%,$(TESTS))
_OBJS = $(wildcard ../obj/*.o)
OBJS = $(patsubst ../obj/main.o,,$(_OBJS))

all: $(OUT)

CC = clang++

CFLAGS = -fuse-ld=mold -I../include

test_%: test_%.cpp
	 $(CC) $(CFLAGS) -o $@ $(OBJS) $< && ./$@
