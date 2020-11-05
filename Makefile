CXXFLAGS=-std=c++11 -Wpedantic -Wall -Wextra -Werror -Wzero-as-null-pointer-constant
CC=g++ -ggdb

compile: main.cpp Process.cpp ProcessManager.cpp ProcessManagerUI.cpp Resource.cpp Utilities.cpp
	$(CC) $(CXXFLAGS) -o icsospm main.cpp Process.cpp ProcessManager.cpp ProcessManagerUI.cpp Resource.cpp Utilities.cpp -I.

clean:
	/bin/rm icsospm core.* vgcore.*
