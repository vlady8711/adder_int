TARGET = output
SYSTEMC = $(SYSTEMC_HOME)
INCDIR = -I. -I$(SYSTEMC)/include
LIBDIR = -L. -L$(SYSTEMC)/lib-linux64
LIBS   = -lsystemc -lm

CC     = g++
CFLAGS = -g -Wno-deprecated -Wall

OBJS   = sc_main.o

EXE    = $(TARGET)

all: $(EXE)

$(EXE): $(OBJS)  
	$(CC) $(CFLAGS) $(INCDIR) $(LIBDIR) -o $@ $(OBJS) $(LIBS) 2>&1

sc_main.o: sc_main.cpp intAdder.h
	$(CC) $(CFLAGS) $(INCDIR) -c $<

check: all
	./$(TARGET)

view: check
	gtkwave *.vcd

clean:
	rm -f $(OBJS) $(EXE) *.vcd
