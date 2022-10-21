#include <bits/stdc++.h>
using namespace std;

void print_array(vector<int>A,int n){
    for(int i=0;i<n;i++){    
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int partition(vector<int>&A,int p,int r){
    int len = A.size();
    int x = A[r];
    int i =  p-1;
    for(int j=p;j<len;j++){
        if(A[j]<x){
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}

void QuickSort(vector<int>&A,int p,int r){
    if(p<r){
        int q = partition(A,p,r);
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
    }
}

int main() {
	vector<int>arr;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	    int x;
	    cin>>x;
	    arr.push_back(x);
	}
	print_array(arr,n);
	QuickSort(arr,0,n-1);
	print_array(arr,n);
	return 0;
}

