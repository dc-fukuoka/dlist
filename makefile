CC     = gcc
CFLAGS = -I./libdlist -g -MMD -MP -Wall
LFLAGS = -L./libdlist -Wl,-rpath=$(PWD)/libdlist
LIBS   = -ldlist
OBJS   = main.o
BIN    = a.out

.SUFFIXES: .c.o
.PHONY: clean

ALL: $(BIN)

$(LIBS): 
	make -C libdlist

.c.o:
	$(CC) -c $(CFLAGS) $<

$(BIN): $(OBJS) $(LIBS)
	$(CC) $(LFLAGS) $(LIBS) $^ -o $@

clean:
	rm -f *.o *.d *~ $(BIN)
	make -C libdlist clean

