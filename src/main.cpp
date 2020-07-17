#include <iostream>
#include <vector>
#include <chrono>
#include "quick_sort.h"
#include "merge_sort.h"

using namespace std;
using namespace std::chrono;

vector<int> random_arr(long size) {
  vector<int> arr;

  for (auto i = 0; i < size; ++i) {
	arr.push_back(rand() % 1000);
  }

  return arr;
}

void display_array(vector<int> arr) {
  cout << "[ ";

  for (auto i = 0; i < arr.size(); ++i) {
	cout << arr[i] << ", ";
  }

  cout << "]" << endl;
}

int main() {
  cout << "Starting the test cases\n";
  auto start = high_resolution_clock::now();
  for (auto i = 0; i < 2; ++i) {
	vector<int> arr = random_arr(100);

//	quick_sort(arr, 0, arr.size() - 1);
	vector<int> sorted_arr = merge_sort(arr);

	for (auto j = 0; j < sorted_arr.size() - 1; ++j) {
	  if (sorted_arr[j] > sorted_arr[j+1]) {
	    cout << "test failed for array" << endl;
	    display_array(arr);
		break;
	  }
	}
	display_array(sorted_arr);
  }

  cout << endl;
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<seconds>(end - start);
  cout << "Test case took " << duration.count() << endl;
  return 0;
}
