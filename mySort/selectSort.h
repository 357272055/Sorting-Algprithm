#ifndef SELECTSORT_H
#define SELECTSORT_H
#include "dataList.h"

template<class T>
void SelectSort(dataList<T>& L, const int left, const int right, int& swapTime){
	swapTime = 0;
	element<T> minValue = L.list[left];
	for(int i = left;i < right;++i){
		for(int j = i + 1;j <= right;++j){
			if(L.list[i] > L.list[j]){
				minValue = L.list[j];
				L.swap(L[i], L[j]);
				++swapTime;
			}
		}
	}
}

#endif
