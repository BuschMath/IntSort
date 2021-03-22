#include "IntSort.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>

using namespace std;

int main()
{
	srand(time(NULL));

	const int listSize = 10000000;
	int chunkSize = 2500000;
	int* selectionList = new int[listSize];
	int* bubbleList = new int[listSize];
	int* insertionList = new int[listSize];
	int* mergeList = new int[listSize];
	int* parallelList = new int[listSize];

	int temp;

	for (int i = 0; i < listSize; i++)
	{
		temp = rand() % RAND_MAX;

		selectionList[i] = temp;
		bubbleList[i] = temp;
		insertionList[i] = temp;
		mergeList[i] = temp;
		parallelList[i] = temp;
	}

	IntSort sorter;
	chrono::time_point<chrono::system_clock> start;
	chrono::time_point<chrono::system_clock> end;
	chrono::duration<float> elapsed;
/*
	start = chrono::system_clock::now();
	sorter.SelectionSort(selectionList, listSize);
	end = chrono::system_clock::now();
	elapsed = end - start;
	cout << "Selection Sort Time: " << elapsed.count() << endl;

	start = chrono::system_clock::now();
	sorter.BubbleSort(bubbleList, listSize);
	end = chrono::system_clock::now();
	elapsed = end - start;
	cout << "Bubble Sort Time: " << elapsed.count() << endl;

	start = chrono::system_clock::now();
	sorter.InsertionSort(insertionList, listSize);
	end = chrono::system_clock::now();
	elapsed = end - start;
	cout << "Insertion Sort Time: " << elapsed.count() << endl;
*/
	start = chrono::system_clock::now();
	sorter.MergeSort(mergeList, 0, listSize - 1);
	end = chrono::system_clock::now();
	elapsed = end - start;
	cout << "Merge Sort Time: " << elapsed.count() << endl;

	start = chrono::system_clock::now();
	sorter.ParallelMergeSort(parallelList, 0, listSize - 1, chunkSize);
	end = chrono::system_clock::now();
	elapsed = end - start;
	cout << "Parallel Merge Sort, Chunck " << chunkSize << " Time: " << elapsed.count() << endl;

	return 0;
}