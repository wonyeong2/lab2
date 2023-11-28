libcalculation.a : add.o subtract.o multiply.o divide.o
	ar rcs libcalculation.a add.o subtract.o multiply.o divide.o
add.o: add.c
	gcc -c add.c
subtract.o: subtract.c
	gcc -c subtract.c
multiply.o: multiply.c
	gcc -c multiply.c
divide.o: divide.c
	gcc -c divide.c
clean:
	fm -f libcalculation.a add.o subtract.o multiply.o divide.o
