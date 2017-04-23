//Divide and Conquer
#include <iostream>
#include <vector>
#include <algorithm>
#include "file_io.h"

using namespace std;

vector<int> divider(vector<int> data, int left, int right){
	//If right and left are equal case
	if(right == left){
		vector<int> temp(3);
		temp[0] = data[left];
		temp[1] = left;
		temp[3] = right;
		return temp;
	}
	
	//Get the middle index
	int middle = (left+right)/2;
	
	//get a right side answer and left side answer
	vector<int> leftans = divider(data, left, middle);
	vector<int> rightans = divider(data, middle+1, right);
	
	//Create right and left max vectors
	vector<int> leftmax(3);
	leftmax[0] = data[middle];
	
	vector<int> rightmax(3);
	rightmax[0] = data[middle+1];
	
	//Check maximum of left side
	int temp=0;
	for(int i=middle; i>=left; i--){
		temp += data[i];
		if(temp > leftmax[0]){
			leftmax[0] = temp;
			leftmax[1] = i;
			leftmax[2] = middle;
		}
	}
	
	//Check maximum of the right side
	temp=0;
	for(int i=middle+1; i<=right; i++){
		temp += data[i];
		if(temp > rightmax[0]){
			rightmax[0] = temp;
			rightmax[1] = middle+1;
			rightmax[2] = i;
		}
	}

	//Setup the leftmax+rightmax vector
	vector<int> result(3);
	result[0] = leftmax[0] + rightmax[0];
	result[1] = leftmax[1];
	result[2] = rightmax[2];
	
	//Figure out which vector holds the largest value
	if(leftans[0] > rightans[0])
		return (leftans[0] > result[0]) ? leftans : result;
	else
		return (rightans[0] > result[0]) ? rightans : result;
}

int main(){
	vector< vector<int> > data = file_input();
	
	for(int i=0; i<data.size(); i++)
		file_output(data[i], divider(data[i], 0, data[i].size()));
	return 0;
}
