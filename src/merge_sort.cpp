//
// Created by Lalit Yadav on 15/07/20.
//

#include "merge_sort.h"

vector<int> merge(vector<int> left, vector<int> right) {
  vector<int> result;

  while (left.size() || right.size()) {
    if (left.size() && right.size()) {
	  if (left.front() < right.front()) {
		result.push_back(left.front());
		left.erase(left.begin());
	  } else {
		result.push_back(right.front());
		right.erase(right.begin());
	  }
    } else if (left.empty()) {
	  for (auto i = 0; i < right.size(); ++i)
		result.push_back(right[i]);
	  break;
	} else {
      for (auto i = 0; i < left.size(); ++i)
		result.push_back(left[i]);
	  break;
	}
  }

  return result;
}

vector<int> merge_sort(vector<int> arr) {
  if (arr.size() <= 1) {
	return arr;
  }

  int mid = (int)(arr.size() + 1) / 2;
  vector<int> left {arr.begin(), arr.begin() + mid};
  vector<int> right {arr.begin() + mid, arr.end()};

  left = merge_sort(left);
  right = merge_sort(right);

  vector<int> result = merge(left, right);

  return result;
}

