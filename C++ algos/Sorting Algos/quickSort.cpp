#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int l, int r)
{
	int pivot = arr[r];
	int i = l-1;
	
	for(int j=l;j<r;j++)
	{
		if(arr[j] < pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	
	swap(arr[i+1],arr[r]);
	return i+1;
	
}


void quicksort(int arr[], int l , int r)
{
	if(l<r){
		int p = partition(arr,l,r);
		quicksort(arr,l,p-1);
		quicksort(arr,p+1,r);
	}
}

int main()
{
	int n; 
  cout << "Enter number of elements: ";
  cin >> n;
	int arr[n];
  cout << "Enter elements seperated by space ";
	for(int i=0;i<n;i++) cin >> arr[i];
	
	quicksort(arr,0,n-1);
	
	for(int i=0;i<n;i++) cout << arr[i] << " ";
	cout << endl;
	
 	return 0;
}
