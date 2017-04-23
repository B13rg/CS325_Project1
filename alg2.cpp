//Better Enumeration

#include <iostream>
#include <vector>
#include "file_io.h"

using namespace std;

int main() {

   vector< vector<int> > data = file_input();

   const int k = data[0].size();

   int best_i, best_j, sum = 0, best_sum = 0;

   for (int i = 0; i < k; i++) {
      sum = 0;
      for (int j = i; j < k; j++) {
	 sum += data[0][j];

	 if (sum > best_sum) {
	    best_sum = sum;
	    best_i = i;
	    best_j = j;
	 }
      }
   }

   vector<int> max_subarray;

   for (int i = best_i; i < best_j+1; i++)
      max_subarray.push_back(data[0][i]);

   file_output(data[0], max_subarray);

   for (int i = best_i; i < max_subarray.size(); i++) {
      cout << max_subarray[i] << ", ";
   }
   cout << endl << best_sum << endl;;

   return 0;
}
