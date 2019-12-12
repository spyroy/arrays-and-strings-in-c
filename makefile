CC=gcc 
AR=ar
MAINOBJECTS=main.o
LIBOBJECTS=Ex3_.o Ex3_.h
LIBa=libEx3_.a
LIBso=libEx3_.so
FLAGS= -Wall -g 

all: Ex3_d Ex3_s mains maind 

mains: $(MAINOBJECTS) $(LIBa)
	$(CC) $(flags) -o mains $(MAINOBJECTS) $(LIBa)
maind: $(MAINOBJECTS)
	$(CC) $(flags) -o maind $(MAINOBJECTS) ./$(LIBso)

Ex3_d: $(LIBOBJECTS)
	$(CC) -shared -o $(LIBso) $(LIBOBJECTS)
Ex3_s: $(LIBOBJECTS)
	$(AR) -rcs $(LIBa) $(LIBOBJECTS)

main.o: main.c Ex3_.h
	$(CC) $(FLAGS) -c main.c
Ex3_.o: Ex3_.c
	$(CC) -fPIC $(FLAGS) -c Ex3_.c

.PHONY: clean all Ex3_d Ex3_s

clean: 
	rm -f *.o mains maind $(LIBso) $(LIBa)



