CC=gcc 
AR=ar
MAINOBJECTS=main.o
LIBOBJECTS=isort.o isort.h 
LIBOBJECTS2=findtxt.o findtxt.h
LIBa=libisort_.a 
LIBa2=libfindtxt_.a
LIBso=libisort.so 
LIBso2=libfindtxt.so
FLAGS= -Wall -g 

all: isortd isorts findtxtd findtxts mains maind 

mains: $(MAINOBJECTS) $(LIBa) $(LIBa2)
	$(CC) $(flags) -o mains $(MAINOBJECTS) $(LIBa) $(LIBa2)
maind: $(MAINOBJECTS)
	$(CC) $(flags) -o maind $(MAINOBJECTS) ./$(LIBso) ./$(LIBso2)

isortd: $(LIBOBJECTS)
	$(CC) -shared -o $(LIBso) $(LIBOBJECTS)
isorts: $(LIBOBJECTS)
	$(AR) -rcs $(LIBa) $(LIBOBJECTS)
findtxtd: $(LIBOBJECTS2)
	$(CC) -shared -o $(LIBso2) $(LIBOBJECTS2)
findtxts: $(LIBOBJECTS2)
	$(AR) -rcs $(LIBa2) $(LIBOBJECTS2)

main.o: main.c isort.h findtxt.h
	$(CC) $(FLAGS) -c main.c
isort.o: isort.c
	$(CC) -fPIC $(FLAGS) -c isort.c
findtxt.o: findtxt.c
	$(CC) -fPIC $(FLAGS) -c findtxt.c

.PHONY: clean all isortd isorts findtxtd fintxts

clean: 
	rm -f *.o mains maind $(LIBso) $(LIBa) $(LIBso2) $(LIBa2)



