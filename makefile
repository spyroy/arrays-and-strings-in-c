CC=gcc 
AR=ar
MAINOBJECTS2=findtxt_main.o
MAINOBJECTS1=isort_main.o
LIBOBJECTS=isort.o isort.h 
LIBOBJECTS2=findtxt.o findtxt.h
LIBa=libisort_.a 
LIBa2=libfindtxt_.a
LIBso=libisort.so 
LIBso2=libfindtxt.so
FLAGS= -Wall -g 

all: isortd isorts findtxtd findtxts isort isort_maind  findtxt findtxt_maind

isort: $(MAINOBJECTS1) $(LIBa)
	$(CC) $(flags) -o isort $(MAINOBJECTS1) $(LIBa) 
isort_maind: $(MAINOBJECTS1)
	$(CC) $(flags) -o isort_maind $(MAINOBJECTS1) ./$(LIBso)
findtxt: $(MAINOBJECTS2) $(LIBa2)
	$(CC) $(flags) -o findtxt $(MAINOBJECTS2) $(LIBa2) 
findtxt_maind: $(MAINOBJECTS2)
	$(CC) $(flags) -o findtxt_maind $(MAINOBJECTS2) ./$(LIBso2)

isortd: $(LIBOBJECTS)
	$(CC) -shared -o $(LIBso) $(LIBOBJECTS)
isorts: $(LIBOBJECTS)
	$(AR) -rcs $(LIBa) $(LIBOBJECTS)
findtxtd: $(LIBOBJECTS2)
	$(CC) -shared -o $(LIBso2) $(LIBOBJECTS2)
findtxts: $(LIBOBJECTS2)
	$(AR) -rcs $(LIBa2) $(LIBOBJECTS2)

isort_main.o: isort_main.c isort.h 
	$(CC) $(FLAGS) -c isort_main.c
findtxt_main.o: findtxt_main.c findtxt.h
	$(CC) $(FLAGS) -c findtxt_main.c
isort.o: isort.c
	$(CC) -fPIC $(FLAGS) -c isort.c
findtxt.o: findtxt.c
	$(CC) -fPIC $(FLAGS) -c findtxt.c

.PHONY: clean all isortd isorts findtxtd fintxts

clean: 
	rm -f *.o isort_mains isort_maind findtxt_mains findtxt_maind $(LIBso) $(LIBa) $(LIBso2) $(LIBa2)



