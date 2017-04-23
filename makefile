.DEFAULT_GOAL := all

all: ALG1 ALG3 ALG4

ALG1:
	g++ -std=c++11 -g -Wall -pedantic -ansi -o algorithm1.sh ./alg1.cpp
	
ALG2:
	g++ -std=c++11 -g -Wall -pedantic -ansi -o algorithm2.sh ./alg2.cpp
	
ALG3:
	g++ -std=c++11 -g -Wall -pedantic -ansi -o algorithm3.sh ./alg3.cpp
	
ALG4:
	g++ -std=c++11 -g -Wall -pedantic -ansi -o algorithm4.sh ./alg4.cpp
	
clean:
	-rm *.sh
