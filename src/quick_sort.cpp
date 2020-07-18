//
// Created by Lalit Yadav on 10/07/20.
//

#include "quick_sort.h"
// Simple Quick sort
//int partition(vector<int>& arr, int start, int end) {
//  auto pivot = arr[end];
//  int p_index = start;
//
//  for (auto i = start; i < end; ++i) {
//	if (arr[i] <= pivot) {
//		swap(arr[i], arr[p_index]);
//		p_index++;
//	}
//  }
//
//  swap(arr[p_index], arr[end]);
//
//  return p_index;
//}
//
//void quick_sort(vector<int>& arr, int start, int end) {
//  if (start < end) {
//    auto p_index = partition(arr, start, end);
//    quick_sort(arr, start, p_index - 1);
//    quick_sort(arr, p_index + 1, end);
//  }
//}

// Three way partition quick sort using dutch national flag algorithm
void partition(vector<int>& arr, int start, int end, int &i, int &j) {
  int mid {arr[end]}, p_index{start};

  while (p_index <= end) {
    if (arr[p_index] < mid)
      std::swap(arr[p_index++], arr[start++]);
    else if (arr[p_index] == mid)
      p_index++;
    else
      std::swap(arr[p_index], arr[end--]);
  }

  i = start - 1;
  j = end;
}

void quick_sort(vector<int>& arr, int start, int end) {
  if (start < end) {
	int i, j;
	partition(arr, start, end, i, j);
	quick_sort(arr, start, i);
	quick_sort(arr, j, end);
  }
}