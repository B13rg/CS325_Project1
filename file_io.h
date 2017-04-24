#ifndef FILE_IO
#define FILE_IO

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//Opens premade file
//Returns vector of vectors holding data from input file
vector<vector<int> > file_input(){
	ifstream file;
	string line;
	vector<vector<int> >values;

	//real filename is "MSS_Problems.txt"
	file.open("MSS_Problems.txt");

	//Go through file and pull data
	if(file.is_open()){
		//Pull each line from file
		while(getline(file, line)){
			int n;
			vector<int> temp;
			stringstream stream(line);

			//For each element, push into temp vector
			for(int i=0; stream; ++i){
				stream >> n;
				temp.push_back(n);
			}
			//Push temp vector into true vector
			values.push_back(temp);
		}
		//Done with file
		file.close();
	}
	return values;
}

void file_output(vector<int> complete, vector<int> sub){
	ofstream file ("MSS_Results.txt", ios::app);
	if(file.is_open()){
		int total =0;
		//Add complete array to file
		for(int i=0; i < complete.size()-1; i++)
			file << complete[i] << " ";
		file << "\n";
		//Add sub array to file
		for(int i=0; i < sub.size()-1; i++){
			total += sub[i];
			file << sub[i] << " ";
		}
		//Add total to file
		file << "\n" << total << "\n\n";
		file.close();
	}
}

#endif
