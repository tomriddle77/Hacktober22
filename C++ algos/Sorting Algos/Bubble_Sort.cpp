#include <iostream>
using namespace std;

void swap(int arr[] , int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubbleSort(int arr[], int n)                   // time complexity is O(n^2)
{
    for(int i=0; i<n-1; i++){
        bool flag=false;
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                flag=true;
                swap(arr, j, j+1);
            }
        }
        if(!flag)                   // if value of flag does not change, it means that the array is alreay sorted
            break;
    }
}

int main()
{
    int arr[] = {3,4,7,2,8,1,5,9,6};
    bubbleSort(arr, 9);

    for(int i=0; i<9; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
