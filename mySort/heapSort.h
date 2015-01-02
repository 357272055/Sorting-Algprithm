#ifndef HEAPSORT_H
#define HEAPSORT_H
#include "maxHeap.h"

template<class E>
void HeapSort(MaxHeap<E>& H, int& swapTime){
	swapTime = 0;
	for(int i = (H.currentSize - 2) / 2;i >= 0;--i)
		H.siftDown(i, H.currentSize - 1);
	for(int i = H.currentSize - 1;i >= 0;--i){
		H.swap(0, i);
		H.siftDown(0, i - 1);
	}
	swapTime = H.swapTime;
}



template<class E>
void HeapSort(MaxHeap<E>& H, const int left, const int right, int& swapTime){
	swapTime = 0;
	for(int i = (right - 1) / 2;i >= 0;--i)
		H.siftDown(i, right);
	for(int i = right;i >= 0;--i){
		H.swap(left, i);
		H.siftDown(left, i - 1);
	}
	swapTime = H.swapTime;
}
#endif
