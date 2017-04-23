//Linear Time
#ifndef ALG4
#define ALG4

#include <iostream>
#include <vector>
#include "file_io.h"

using namespace std;

vector<int> linearTime(vector<int> data){
	int max_so_far = 0, max_ending_here = 0;
	vector<int> temp, max; 

	for(int i = 0; i < data.size(); i++){
		max_ending_here = max_ending_here + data[i];
		temp.push_back(data[i]);
		if(max_ending_here < 0){
			max_ending_here = 0;
			temp.clear();
		}
		else if (max_so_far < max_ending_here){
			max_so_far = max_ending_here;
			max = temp;	
		}
	}

	return max; 
}

#endif

/*
int main(){
	vector<vector<int>> data = file_input();

	for(int i = 0;  i < data.size(); i++){
		//file_output(data[i], linearTime(data[i]));
	}
	return 0;
}
*/
