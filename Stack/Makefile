# In The Name Of God
# ========================================
# [] File Name : Makefile
#
# [] Creation Date : 25-02-2015
#
# [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
# =======================================

P=stack
OBJ=stack.o main.o
LIB=
MLIB=

ifdef LIB
CFLAGS=-Wall -O0 -g -std=gnu11 \
       $(shell pkg-config --cflags $(LIB))
LDLIBS=$(shell pkg-config --libs $(LIB)) $(MLIB)
else
CFLAGS=-Wall -O0 -g -std=gnu11
LDLIBS=$(MLIB)
endif
ASFLAGS=-Wall -O0 -g

$(P): $(OBJ)
	$(CC) -o $(P) $(OBJ) $(LDLIBS)
main.o: stack.h
stack.o: stack.h

.PHONY: clean
clean:
	rm $(OBJ) $(P)
