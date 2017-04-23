//Better Enumeration
#ifndef ALG2
#define ALG2

#include <iostream>
#include <vector>
#include "file_io.h"

using namespace std;

vector<int> better_enumerate(vector<int> data) {
   const int k = data.size();

   int best_i, best_j, sum = 0, best_sum = 0;

   for (int i = 0; i < k; i++) {
     sum = 0;
     for (int j = i; j < k; j++) {
	 	sum += data[j];

	 	if (sum > best_sum) {
	 	   best_sum = sum;
	 	   best_i = i;
	 	   best_j = j;
	 	}
     }
   }

   vector<int> max_subarray;

   for (int i = best_i; i < best_j+1; i++)
      max_subarray.push_back(data[i]);
      
	return max_subarray;
}

#endif
