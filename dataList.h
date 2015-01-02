#ifndef DATALIST_H
#define DATALIST_H
#include <iostream>

const int DefaultSize = 100;

template<class T>
class element{
	public:
		T key;
		element<T>& operator = (element<T>& ele){
			key = ele.key;
			return *this;
		}

		element<T>& operator = (const T k){
			key = k;
			return *this;
		}

		bool operator == (element<T>& ele){
			return key == ele.key;
		}

		bool operator > (element<T>& ele){
			return key > ele.key;
		}

		bool operator < (element<T>& ele){
			return key < ele.key;
		}

		bool operator >= (element<T>& ele){
			return key >= ele.key;
		}

		bool operator <= (element<T>& ele){
			return key <= ele.key;
		}
};


template<class T>
class dataList{
	public:
		dataList(int maxSz = DefaultSize):maxSize(maxSz), currentSize(0){list = new element<T>[maxSize];}
		void swap(element<T>& x, element<T>& y){
			element<T> temp = x;
			x = y;
			y = temp;
		}
		int length(){return currentSize;}
		element<T>& operator[] (int i){return list[i];}
		int partition(const int low, const int high, int& swapTime);
	//private:
		element<T>* list;
		int maxSize;
		int currentSize;
};


template<class T>
int dataList<T>::partition(const int low, const int high, int& swapTime){
	int pivotPos = low;
	element<T> pivot = list[low];
	for(int i = low + 1;i <= high;++i){
		if(list[i] < pivot){
			++pivotPos;
			if(pivotPos != i){
				swap(list[pivotPos], list[i]);
				swapTime += 2;
			}
		}
	}
	list[low] = list[pivotPos];
	list[pivotPos] = pivot;
	swapTime += 2;
	return pivotPos;
}


#endif
