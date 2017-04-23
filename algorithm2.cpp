#include "alg2.h"
#include "file_io.h"

using namespace std;

int main(){
	vector< vector<int> > data = file_input();

	for(int i=0; i<data.size(); i++)
		file_output(data[i], better_enumerate(data[i]));
	return 0;
}
