//Enumeration
#ifndef ALG1
#define ALG1

#include <iostream>
#include <vector>
#include "file_io.h"

using namespace std;

vector<int> enumeration(vector<int> data){
	int temp=0, index[2];
	vector<vector<int> > holder;
	
	//Go through and enumarate the totals of each line
	for(int i=0; i<data.size(); i++){
		vector<int> blue(data.size());
		for(int j=i; j<data.size(); j++){
			temp += data[j];
			blue[j]=temp;
		}
		holder.push_back(blue);
		temp = 0;
	}

	//Search for largest
	int sum = holder[0][0];	//get inital value for sum
	for(int i=0; i<data.size(); i++)
		for(int j=i; j<data.size(); j++)
			if(holder[i][j] > sum){
				sum = holder[i][j];
				index[0] = i;
				index[1] = j;
			}
	
	//Create the sub array of values and return it
	vector<int>::const_iterator first = data.begin()+index[0];
	vector<int>::const_iterator last = data.begin()+index[1]+1;
	vector<int> newvec (first, last);
	return newvec;
}

#endif
