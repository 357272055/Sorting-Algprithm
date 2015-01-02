#ifndef MERGESORT_H
#define MERGESORT_H
#include "dataList.h"

template<class T>
void Merge(dataList<T>& L1, dataList<T>& L2, const int left, const int middle, const int right, int& swapTime){
	for(int k = left;k <= right;++k)
		L2[k] = L1[k];
	int point1 = left, point2 = middle + 1, t = left;
	while(point1 <= middle && point2 <= right){
		if(L2[point1] > L2[point2]){
			L1[t++] = L2[point2++];
			++swapTime;
		}
		else{
			L1[t++] = L2[point1++];
			++swapTime;
		}
	}

	while(point1 <= middle){
		L1[t++] = L2[point1++];
		++swapTime;
	}
	while(point2 <= right){
		L1[t++] = L2[point2++];
		++swapTime;
	}
}


template<class T>
void MergeSort(dataList<T>& L, dataList<T>& L2, const int left, const int right, int& swapTime){
	if(left >= right)return;
	int middle = (left + right) / 2;
	MergeSort(L, L2, left, middle, swapTime);
	MergeSort(L, L2, middle + 1, right, swapTime);
	Merge(L, L2, left, middle, right, swapTime);
}



template<class T>
void MergeSort(dataList<T>& L, int left, int right, int& swapTime){
	if(right == -1)
		right = L.currentSize - 1;
	swapTime = 0;
	dataList<T> L2(right - left);
	MergeSort(L, L2, left, right, swapTime);
}
#endif
