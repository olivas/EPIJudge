#include <vector>
#include <algorithm>
#include <iostream>

#include "test_framework/generic_test.h"
using std::vector;

// A is passed by value argument, since we change it.
int FindFirstMissingPositive(vector<int> A) {
  // 1) sort the array
  // 2) iterate and track the diff between this and last
  //    if diff > 1 then return last + 1
  // the running time is dominated by the sort - O(NlogN)
  // the second loop is O(N)
  std::sort(std::begin(A), std::end(A));

  int last{*(A.begin())};
  for(auto iter = A.begin()++; iter != A.end(); ++iter){
      std::cout<<"("<<last<<" "<<*iter<<")"<<std::endl;
      int diff = *iter - last;
      if(*iter > 0 && diff > 1){
          if(last <= 0)
              return 1;
          return last + 1;
      }
      last = *iter;
  }
  return 0;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  return GenericTestMain(args, "first_missing_positive_entry.cc",
                         "first_missing_positive_entry.tsv",
                         &FindFirstMissingPositive, DefaultComparator{},
                         param_names);
}
