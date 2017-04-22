//Enumeration
#include <iostream>
#include <vector>
#include "file_io.h"

using namespace std;

vector<int> enumeration(vector<int> data){
	int sum=0, temp=0;
	int index[2];
	vector<vector<int> > holder;
	for(int i=0; i<data.size()-1; i++){
		vector<int> blue(data.size());
		for(int j=i; j<data.size(); j++){
			temp += data[j];
			blue[j]=temp;
		}
		holder.push_back(blue);
	}

	//Search for largest
	for(int i=0; i<data.size()-1; i++){
		for(int j=i; j<data.size(); j++){
			if(holder[i][j] > sum){
				index[0] = i;
				index[1] = j;
			}
		}
	}

	vector<int>::const_iterator first = data.begin()+index[0];
	vector<int>::const_iterator last = data.begin()+index[1]+1;
	vector<int> newvec (first, last);
	return newvec;
}

int main(){

	vector< vector<int> > data = file_input();
	vector<int> temp = enumeration(data[0]);

	for(int i=0; i<temp.size(); i++)
		cout << temp[i] << " ";
	

	//file_output(data[0], data[0]);
	return 0;
}
