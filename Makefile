CFLAGS = -Wall -pedantic -Werror
LFLAGS = `sdl-config --libs` -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
OBJS   = audio.o bird.o collision.o draw.o fonts.o graphics.o init.o input.o pipe.o demonbird.o
PROG = demonbird
CXX = gcc

# top-level rule to create the program.
all: $(PROG)

# debugging flags
debug: CFLAGS += -O0 -g -DDEBUG
debug: $(PROG)

include Sourcedeps

# compiling other source files.
%.o: src/%.c src/%.h  src/types.h
	$(CXX) $(CFLAGS) -c -s $<

# linking the program.
$(PROG): $(OBJS)
	$(CXX) $(OBJS) -o $(PROG) $(LFLAGS)

# cleaning everything that can be automatically recreated with "make".
clean:
	rm $(PROG) *.o

.PHONY: all clean debug
