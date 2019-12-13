CC=gcc 
AR=ar
MAINOBJECTS=main.o
LIBOBJECTS=isort.o isort.h
LIBa=libisort_.a
LIBso=libisort.so
FLAGS= -Wall -g 

all: isortd isorts mains maind 

mains: $(MAINOBJECTS) $(LIBa)
	$(CC) $(flags) -o mains $(MAINOBJECTS) $(LIBa)
maind: $(MAINOBJECTS)
	$(CC) $(flags) -o maind $(MAINOBJECTS) ./$(LIBso)

isortd: $(LIBOBJECTS)
	$(CC) -shared -o $(LIBso) $(LIBOBJECTS)
isorts: $(LIBOBJECTS)
	$(AR) -rcs $(LIBa) $(LIBOBJECTS)

main.o: main.c isort.h
	$(CC) $(FLAGS) -c main.c
isort.o: isort.c
	$(CC) -fPIC $(FLAGS) -c isort.c

.PHONY: clean all isortd isorts

clean: 
	rm -f *.o mains maind $(LIBso) $(LIBa)



