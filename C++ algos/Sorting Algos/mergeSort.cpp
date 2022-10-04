#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int l,int m,int r){
      int n1=m-l+1, n2=r-m;
      int left[n1],right[n2];
       for(int i=0;i<n1;i++)
        left[i]=arr[i+l];
    for(int j=0;j<n2;j++)
        right[j]=arr[m+1+j];    
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(left[i]<=right[j])
            arr[k++]=left[i++];
        else
            arr[k++]=right[j++];
    }
    while(i<n1)
        arr[k++]=left[i++];
    while(j<n2)
        arr[k++]=right[j++];   
}



void mergesort(int arr[],int l,int r){
    if(r>l){
        int m=(l+r)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main(){
    int n;
    cout<<"Enter size of array"<<"\n";
    cin>>n;
    int arr[n];
    cout<<"Enter values in array"<<"\n";  //taking array input from user
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    	int l=0,r=n-1;
	//calling mergesSort function
	mergesort(arr,l,r);
	cout<<"Sorted array =";
	for(int x: arr)
	    cout<<x<<" ";
}

