#include<bits/stdc++.h>
using namespace std ; 

// Function to Implement bubble Sort Algo
void bubble (int arr[] , int n){
    int i , j ;
    for(i = 0 ; i < n -1 ; i++){
        for(j = 0 ; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to print an array
void printArr(int arr[] , int n){
    for(int i = 0 ; i< n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main() {
    int arr[] = {10, 5 , 6 , 4 , 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"Un-Sorted Array : "<<endl;
    printArr(arr,n);

    bubble(arr, n);

    cout<<"Sorted Array - "<<endl;
    printArr(arr,n);

    return 0;
}