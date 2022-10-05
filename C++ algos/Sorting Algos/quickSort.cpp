// C++ - Quick Sort Algorithm.
#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int start, int end)
{

	int pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	// Sorting left and right parts of the pivot element
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

	if (start >= end)
		return;

	// partitioning the array
	int p = partition(arr, start, end);

	// Sorting the left part
	quickSort(arr, start, p - 1);

	// Sorting the right part
	quickSort(arr, p + 1, end);
}

void printArr(int arr[], int n){
    for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
    cout<<"\n";
}

int main()
{

	int arr[] = { 10, 3, 22, 1, 3, 82 , 5 , 55};
	int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"Unsorted Array :"<<endl;
    printArr( arr,  n);
    
	quickSort(arr, 0, n - 1);

    cout<<"Sorted Array :"<<endl;
    printArr( arr,  n);


	return 0;
}
