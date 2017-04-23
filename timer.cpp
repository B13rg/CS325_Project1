#include "alg1.h"
//#include <alg2.h>
#include "alg3.h"
//#include <alg4.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <ctime>

using namespace std::chrono;
using namespace std;

int main(){
	srand(time(NULL));
	
	duration<double> times[4][4];	//Duration intializes to 0
	
	/*We need to create the following lengths of numbers:
		10 values
		100 values
		1,000 values
		10,000 values		
	*/
	vector<vector<int> > tens(5, vector<int> (10));
	vector<vector<int> > hundred(5, vector<int> (100));
	vector<vector<int> > thousand(5, vector<int> (1000));
	vector<vector<int> > tenthous(5, vector<int> (10000));
	
	
	//Fill vectors with values
	//Values will be between -50 and 50
	for(int i=0; i<5; i++){
		//10 values
		for(int j=0; j< 10; j++)
			tens[i][j] = rand()%101-50;
		//100s values
		for(int j=0; j< 100; j++)
			hundred[i][j] = rand()%101-50;
		//1,000s values
		for(int j=0; j< 1000; j++)
			thousand[i][j] = rand()%101-50;
		//10,000s values
		for(int j=0; j< 10000; j++)
			tenthous[i][j] = rand()%101-50;
	}	
	
	//for each algorithm run each 5 times
	
	//alg1
	for(int i=0; i<5; i++){
		chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
		enumeration(tens[i]);
		chrono::high_resolution_clock::time_point finish = chrono::high_resolution_clock::now();
		times[0][0] += duration_cast<duration<double>>(finish-start);		
	}
	for(int i=0; i<5; i++){
		chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
		enumeration(hundred[i]);
		chrono::high_resolution_clock::time_point finish = chrono::high_resolution_clock::now();
		times[0][1] += duration_cast<duration<double>>(finish-start);		
	}
	for(int i=0; i<5; i++){
		chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
		enumeration(thousand[i]);
		chrono::high_resolution_clock::time_point finish = chrono::high_resolution_clock::now();
		times[0][2] += duration_cast<duration<double>>(finish-start);		
	}
	for(int i=0; i<5; i++){
		chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
		enumeration(tenthous[i]);
		chrono::high_resolution_clock::time_point finish = chrono::high_resolution_clock::now();
		times[0][3] += duration_cast<duration<double>>(finish-start);		
	}
	//alg2
	
	//alg3
	for(int i=0; i<5; i++){
		chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
		divider(tens[i], 0, tens[i].size());
		chrono::high_resolution_clock::time_point finish = chrono::high_resolution_clock::now();
		times[2][0] += duration_cast<duration<double>>(finish-start);		
	}
	for(int i=0; i<5; i++){
		chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
		divider(hundred[i], 0, hundred[i].size());
		chrono::high_resolution_clock::time_point finish = chrono::high_resolution_clock::now();
		times[2][1] += duration_cast<duration<double>>(finish-start);		
	}
	for(int i=0; i<5; i++){
		chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
		divider(thousand[i], 0, thousand[i].size());
		chrono::high_resolution_clock::time_point finish = chrono::high_resolution_clock::now();
		times[2][2] += duration_cast<duration<double>>(finish-start);		
	}
	for(int i=0; i<5; i++){
		chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
		divider(tenthous[i], 0, tenthous[i].size());
		chrono::high_resolution_clock::time_point finish = chrono::high_resolution_clock::now();
		times[2][3] += duration_cast<duration<double>>(finish-start);		
	}
	//alg4
	
	
	//Clean up results and output to screen
	for(int i=0; i< 4; i++){
		for(int j=0; j<4; j++)
			cout << times[i][j].count() / 5 << ",";
		cout << endl;
	}
		
	return 0;
}
