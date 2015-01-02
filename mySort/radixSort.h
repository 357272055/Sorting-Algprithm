#ifndef MSDSORT_H
#define MSDSORT_H
#include "dataList.h"
#include "insertSort.h"

const int radix = 10;

template<class T>
int getDigit(const element<T>& ele, int d){
	int num = ele.key;
	for(int i = 1;i < d;++i)
		num /= 10;
	while(num >= 10)
		num %= 10;
	return num;
}

template<class T>
int maxBit(dataList<T> L, int n){
	int mb = 1;
	int p = 10;
	for(int i = 0;i < n;++i)
		while(L[i].key >= p){
			p *= 10;
			++mb;
		}
	return mb;
}


template<class T>
void RadixSort(dataList<T>& L, const int left, const int right, int& swapTime){
	swapTime = 0;
	int d = maxBit(L, right - left + 1);
	int n = right - left + 1;
	element<T>* temp = new element<T>[n];
	int* count = new int[10];
	int i, j, k;
	int radix = 1;

	for(i = 1;i <= d;++i){
		for(j = 0;j < 10;++j)
			count[j] = 0;
		for(j = left;j <= right;++j){
			k = (L[j].key / radix) % 10;
			++count[k];
		}
		for(j = 1;j < 10;++j)
			count[j] = count[j - 1] + count[j];
		for(j = right;j >= 0;--j){
			k = (L[j].key / radix) % 10;
			temp[count[k] - 1] = L[j];
			--count[k];
		}
		for(j = left;j <= right;++j){
			L[j] = temp[j];
			++swapTime;
		}
		radix *= 10;
	}
	delete [] temp;
	delete [] count;
}


#endif
