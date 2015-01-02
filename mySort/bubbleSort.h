#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include "dataList.h"

template<class T>
void BubbleSort(dataList<T>& L, const int left, const int right, int& swapTime){
	swapTime = 0;
	int pass = left;
	int exchange = 1;
	while(pass <= right && exchange){
		BubbleExchange(L, pass, exchange, right, swapTime);
		++pass;
	}
}


template<class T>
void BubbleExchange(dataList<T>& L, const int i, int& exchange, const int right, int& swapTime){
	exchange = 0;
	for(int j = right;j >= i;--j)
		if(L.list[j - 1] > L.list[j]){
			L.swap(L.list[j - 1], L.list[j]);
			swapTime += 2;
			exchange = 1;
		}
}
#endif
