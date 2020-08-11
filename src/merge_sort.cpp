//
// Created by Lalit Yadav on 15/07/20.
//

#include "merge_sort.h"

// Not fast since we are erasing first element of the vector so O(n)
vector<int> merge(vector<int> left, vector<int> right) {
  vector<int> result;

  while (!left.empty() || !right.empty()) {
	 if (left.empty() || right.empty()) {
		if (left.empty()) {
		 for (int i : right)
			result.push_back(i);
		 break;
		} else {
		 for (int i : left)
			result.push_back(i);
		 break;
		}
	 } else {
		if (left.front() < right.front()) {
		 result.push_back(left.front());
		 left.erase(left.begin());
		} else {
		 result.push_back(right.front());
		 right.erase(right.begin());
		}
	 }
	}

  return result;
}

// Optimised merge function
//vector<int> merge(vector<int>& left, vector<int>& right, long &num_inversions) {
//	vector<int> result;
//	int l_index {0}, r_index{0};
//	int l_size {static_cast<int>(left.size())};
//	int r_size {static_cast<int>(right.size())};
//
//	while (l_size > 0 && r_size > 0) {
//		if (left[l_index] > right[r_index]) {
//			num_inversions += l_size;
//			result.push_back(right[r_index++]);
//			r_size--;
//		} else {
//			result.push_back(left[l_index++]);
//			l_size--;
//		}
//	}
//
//	if (r_size <= 0) {
//		for (int i = l_index; i < left.size(); ++i)
//			result.push_back(left[i]);
//		return result;
//	}
//
//	for (int i = r_index; i < right.size(); ++i)
//			result.push_back(right[i]);
//
//	return result;
//}


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

