#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "dataList.h"


template<class T>
void QuickSort(dataList<T>& L, const int left, const int right, int& swapTime){
	swapTime = 0;
	QuickSort(left, right, swapTime, L);
}

template<class T>
void QuickSort(const int left, const int right, int& swapTime, dataList<T>& L){
	if(left < right){
		int pivotPos = L.partition(left, right, swapTime);
		QuickSort(left, pivotPos - 1, swapTime, L);
		QuickSort(pivotPos + 1, right, swapTime, L);
	}
}
#endif
