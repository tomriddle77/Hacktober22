#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
     vector<int> v;
     int i=l,j=m+1;
     while(i<=m&&j<=r)
     {
         if(arr[i]<arr[j])
         {
             v.push_back(arr[i]);
             i++;
         }
         else
         {
             v.push_back(arr[j]);
             j++;
         }
     }
     while(i<=m)
     {
         v.push_back(arr[i]);
         i++;
     }
     while(j<=r)
     {
         v.push_back(arr[j]);
         j++;
     }
     for(int i=0;i<v.size();i++)
     arr[l+i]=v[i];
}

void mergeSort(int arr[], int l, int r)
{
    if(l>=r)
    return;
    int m=l+(r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

int main()
{
    int n;
    int arr[n];
    
    cout<<"Enter array elements\n";
    for(int i=0;i<n;i++)
      cin>>arr[i];
  
    mergeSort(arr, 0, n-1);
    
    cout<<"Sorted array elements:\n";
    for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
    
    return 0;
}
