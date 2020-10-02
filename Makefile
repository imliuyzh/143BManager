CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant
CC=g++ -ggdb

compile: main.cpp Process.cpp ProcessManager.cpp ProcessManagerUI.cpp Resource.cpp Utilities.cpp
	echo     ------------compiling files to create executable program----------------
	$(CC) $(CXXFLAGS) -o icsospm main.cpp Process.cpp ProcessManager.cpp ProcessManagerUI.cpp Resource.cpp Utilities.cpp -I.

clean:
	echo ----------------removing executable program--------------------
	/bin/rm icsospm core.*
