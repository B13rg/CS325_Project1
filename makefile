.DEFAULT_GOAL := all

all: ALG1 ALG2 ALG3 ALG4

ALG1:
	g++ -g -Wall -pedantic -ansi -std=c++11 -o algorithm1.sh ./algorithm1.cpp
	
ALG2:
	g++ -g -Wall -pedantic -ansi -std=c++11 -o algorithm2.sh ./algorithm2.cpp
	
ALG3:
	g++ -g -Wall -pedantic -ansi -std=c++11 -o algorithm3.sh ./algorithm3.cpp
	
ALG4:
	g++ -g -Wall -pedantic -ansi -std=c++11 -o algorithm4.sh ./algorithm4.cpp

timer:
	g++ -g -Wall -pedantic -ansi -std=c++11 -o timer.sh ./timer.cpp
clean:
	-rm *.sh
