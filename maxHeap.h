#ifndef MAXHEAP_H
#define MAXHEAP_H
#include "dataList.h"

template<class T>
class MaxHeap{
	public:
		MaxHeap(int sz = 10);
		MaxHeap(dataList<T>& L, int mSz = 10);
		~MaxHeap(){delete[] heap;}
		bool Insert(element<T>& x);
		bool Remove(element<T>& x);
		bool isEmpty(){return currentSize == 0;}
		bool isFull(){return maxHeapSize == currentSize;}
		element<T> operator[] (int i){return heap[i];}
	private:
		element<T>* heap;
		int currentSize;
		int maxHeapSize;
		int swapTime;
		void siftDown(int start, int m);
		void siftUp(int start);
		void swap(const int i, const int j){
			++swapTime;
			element<T> temp = heap[i];
			heap[i] = heap[j];
			heap[j] = temp;
		}

		template<class E>
		friend void HeapSort(MaxHeap<E>& H, int& swapTime);
		template<class E>
		friend void HeapSort(MaxHeap<E>& H, const int left, const int right, int& swapTime);
};

template<class T>
MaxHeap<T>::MaxHeap(int sz){
	maxHeapSize = sz;
	swapTime = 0;
}

template<class T>
MaxHeap<T>::MaxHeap(dataList<T>& L, int mSz){
	swapTime = 0;
	heap = new element<T>[L.currentSize];
	currentSize = L.currentSize;
	maxHeapSize = L.maxSize;
	for(int i = 0;i < currentSize;++i)
		heap[i] = L[i];
} 

template<class T>
void MaxHeap<T>::siftDown(const int start, const int m){
	int i = start;
	int j = 2 * i + 1;
	element<T> temp = heap[i];
	while(j <= m){
		if(j < m && heap[j] < heap[j + 1])++j;
		if(temp >= heap[j])break;
		else{
			heap[i] = heap[j];
			++swapTime;
			i = j;
			j = 2 * j + 1;
		}
	}
	heap[i] = temp;
}


#endif
