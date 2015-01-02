#ifndef MYALGORITHM_H_
#define MYALGORITHM_H_
#include "dataList.h"
#include "maxHeap.h"



///BUBBLESORT
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
///BUBBLESORT


///INSERTSORT
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


///INSERTSORT

///SELECTSORT

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
///SELECTSORT

///QUICKSORT
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
///QUICKSORT

///HEAPSORT
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
///HEAPSORT


///MERGESORT
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
///MERGESORT


///RADIXSORT
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


///RADIXSORT
#endif
