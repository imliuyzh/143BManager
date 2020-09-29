CXXFLAGS=-std=c++17 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant
CC=g++ -ggdb

#testSortedList: testSortedList.o SortedLinkedList.o SortedArrayList.o
#	echo     ------------compiling files to create executable program----------------
#	$(CC) $(CXXFLAGS) -o testSortedList testSortedList.o SortedLinkedList.o SortedArrayList.o

#clean:
#	echo ----------------removing executable program--------------------
#	/bin/rm testSortedList.o SortedArrayList.o SortedLinkedList.o testSortedList
