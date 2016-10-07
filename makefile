project1: project1.o
	gcc project1.o -o project1
project1.o: project1.c

test: test1 test2 test3 test 4
test1:
	./project1 HELLO 0 data.txt data.out
test2:
	./project1 HELLO 1 data.out data.bak
	diff -s data.txt data.bak
test3:
	./project1 FEATHER 0 file.txt file.out
test4:
	./project1 FEATHER 1 file.out file.bak
	diff -s file.txt file.bak
