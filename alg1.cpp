//Enumeration
#include <iostream>
#include <vector>
#include "file_io.h"

using namespace std;

int main(){

	vector< vector<int> > data = file_input();
		
	
	file_output(data[0], data[0]);
	return 0;
}
