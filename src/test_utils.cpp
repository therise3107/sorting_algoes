//
// Created by Lalit Yadav on 15/07/20.
//

#include "test_utils.h"

void display_array(vector<int> arr) {
  cout << "[ ";

  for (auto i = 0; i < arr.size(); ++i) {
	cout << arr[i] << ", ";
  }

  cout << "]" << endl;
}

vector<int> gen_random_arr(long size) {
  vector<int> arr;

  for (auto i = 0; i < size; ++i) {
	arr.push_back(rand() % 1000);
  }

  return arr;
}
