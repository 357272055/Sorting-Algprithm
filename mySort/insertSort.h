#ifndef INSERTSORT_H
#define INSERTSORT_H
#include "dataList.h"

template<class T>
void InsertSort(dataList<T>& L, const int left, const int right, int& swapTime){
	swapTime = 0;
	element<T> temp;
	int i, j;
	for(i = left + 1;i <= right;++i)
		if(L[i] < L[i - 1]){
			temp = L[i];
			j = i - 1;
			do{
				L[j + 1] = L[j];
				++swapTime;
				--j;
			}while(j >= left && temp < L[j]);
			L[j + 1] = temp;
		}
}


template<class T>
void BinInsertSort(dataList<T>& L, const int left, const int right, int& swapTime){
	swapTime = 0;
	element<T> temp;
	int low, high, middle;
	for(int i = left + 1;i <= right;++i){
		temp = L[i];
		low = left;
		high = i - 1;
		while(low <= high){
			middle = (low + high) / 2;
			if(temp < L[middle])
				high = middle - 1;
			else
				low = middle + 1;
		}
		for(int k = i - 1;k >= low; --k){
			L[k + 1] = L[k];
			++swapTime;
		}
		L[low] = temp;
	}
}

template<class T>
void ShellSort(dataList<T>& L, const int left, const int right, int& swapTime){
	swapTime = 0;
	element<T> temp;
	int j, gap = right - left + 1;
	do{
		gap = gap / 3 + 1;
		for(int i = left + gap;i <= right;++i)
			if(L[i] < L[i - gap]){
				temp = L[i];
				j = i - gap;
				do{
					L[j + gap] = L[j];
					++swapTime;
					j -= gap;
				}while(j >= left && temp < L[j]);
				L[j + gap] = temp;
			}
	}while(gap > 1);
}

#endif
