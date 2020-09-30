CXXFLAGS=-std=c++17 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant
CC=g++ -ggdb

compile: main.cpp Process.cpp ProcessManager.cpp ProcessManagerUI.cpp Resource.cpp Utilities.cpp
	echo     ------------compiling files to create executable program----------------
	$(CC) $(CXXFLAGS) -o icsospm main.cpp Process.cpp ProcessManager.cpp ProcessManagerUI.cpp Resource.cpp Utilities.cpp -I.

clean:
	echo ----------------removing executable program--------------------
	/bin/rm icsospm main.o Process.o ProcessManager.o ProcessManagerUI.o Resource.o Utilities.o

#testSortedList: testSortedList.o SortedLinkedList.o SortedArrayList.o
#	echo     ------------compiling files to create executable program----------------
#	$(CC) $(CXXFLAGS) -o testSortedList testSortedList.o SortedLinkedList.o SortedArrayList.o

#clean:
#	echo ----------------removing executable program--------------------
#	/bin/rm testSortedList.o SortedArrayList.o SortedLinkedList.o testSortedList
