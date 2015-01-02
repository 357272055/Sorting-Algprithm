#include "myAlgorithm.h"
#include <ctime>
using namespace std;

void help();

template<class T>
void ranList(dataList<T>& L, int start, int end);



int main(){
	srand((unsigned)time(0));
	int n;//amount of random numbers
	int swapTime = 0;
	float _start, _end;
	int order = 0;
	help();
	cout << "Enter the amount of random numbers: ";
	cin >> n;
	dataList<int> List(n);
	List.currentSize = n;
	MaxHeap<int>* Heap;


	while(order != -1){
		cout << "Select sorting algorithm(1 ~ 9): ";
		cin >> order;
		if(order >= 1 && order <= 9){
			ranList(List, 0, n);
			swapTime = 0;
			_start = clock();
		}else if(order == 0)
			order = -1;
		else{
			cout << "wrong input\n";
			order = 0;
			break;
		}

		switch(order){
			case 1: BubbleSort(List, 0, n, swapTime);
					_end = clock();
					cout << "Bubble Sort\n" <<"Time spent: " << _end - _start << " ms\n"
					   << "Swap time: " << swapTime << " times\n";
					break;
			case 2: SelectSort(List, 0, n, swapTime);
					_end = clock();
					cout << "Select Sort\n" << "Time spent: " << _end - _start << " ms\n"
					   << "Swap time: " << swapTime << " times\n";
					break;
			case 3: InsertSort(List, 0, n, swapTime);
					_end = clock();
					cout << "Direct Insert Sort\n" << "Time spent: " << _end - _start << " ms\n"
					   << "Swap time: " << swapTime << " times\n";
					break;
			case 4: BinInsertSort(List, 0, n, swapTime);
					_end = clock();
					cout << "Binary Insert Sort\n" << "Time spent: " << _end - _start << " ms\n"
					   << "Swap time: " << swapTime << " times\n";
					break;
			case 5: ShellSort(List, 0, n, swapTime);
					_end = clock();
					cout << "Shell Sort\n" << "Time spent: " << _end - _start << " ms\n"
					   << "Swap time: " << swapTime << " times\n";
					break;
			case 6: QuickSort(List, 0, n, swapTime);
					_end = clock();
					cout << "Quick Sort\n" << "Time spent: " << _end - _start << " ms\n"
					   << "Swap time: " << swapTime << " times\n";
					break;
			case 7: Heap = new MaxHeap<int>(List, n * 2);
					HeapSort(*Heap, 0, n, swapTime);
					_end = clock();
					cout << "Heap Sort\n" << "Time spent: " << _end - _start << " ms\n"
					   << "Swap time: " << swapTime << " times\n";
					break;
			case 8: MergeSort(List, 0, n, swapTime);
					_end = clock();
					cout << "Merge Sort\n" << "Time spent: " << _end - _start << " ms\n"
					   << "Swap time: " << swapTime << " times\n";
					break;
			case 9: RadixSort(List, 0, n, swapTime);
					_end = clock();
					cout << "Radix Sort\n" << "Time spent: " << _end - _start << " ms\n"
					   << "Swap time: " << swapTime << " times\n";
					break;
		}
		cout << endl;

	}
}


void help(){
	cout << "===========================================================\n";
	cout << "|---------- 1 . Bubble Sort ------------------------------|\n";
	cout << "|---------- 2 . Select Sort ------------------------------|\n";
	cout << "|---------- 3 . Direct Insert Sort -----------------------|\n";
	cout << "|---------- 4 . Binary INsert Sort -----------------------|\n";
	cout << "|---------- 5 . Shell Sort -------------------------------|\n";
	cout << "|---------- 6 . Quick Sort -------------------------------|\n";
	cout << "|---------- 7 . Heap Sort --------------------------------|\n";
	cout << "|---------- 8 . Merge Sort -------------------------------|\n";
	cout << "|---------- 9 . Radix Sort -------------------------------|\n";
	cout << "|---------- 0 . Quit -------------------------------------|\n";
	cout << "===========================================================\n";
	
}



template<class T>
void ranList(dataList<T>& L, int start, int end){
	for(int i = 0;i < L.currentSize;++i)
		L[i] = rand() % (end - start + 1);
}
