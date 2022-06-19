BINARY=bin
CODEDIRS=. lib
INCDIRS=. ./include/

CC=gcc # clang
VERSION=c11
OPT=-O0
DEPFLAGS=-MP -MD
LINKFLAGS =`sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf -lm
CFLAGS=-Wall -Werror -Wextra -std=$(VERSION) -g $(foreach D,$(INCDIRS),-I$(D)) $(OPT) $(DEPFLAGS)

CFILES=$(foreach D,$(CODEDIRS),$(wildcard $(D)/*.c))

OBJECTS=$(patsubst %.c,%.o,$(CFILES))
DEPFILES=$(patsubst %.c,%.d,$(CFILES))

all:$(BINARY)

$(BINARY):$(OBJECTS)
	$(CC) -o $@ $^ $(LINKFLAGS)

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BINARY) $(OBJECTS) $(DEPFILES)

run: bin
	./bin