#include <bits/stdc++.h>
using namespace std;

void print_array(vector<int>A,int n){
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}


void Merge(vector<int>&A,int p,int q,int r){
    int i=1,j=1;
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1+1];
    int R[n2+1];
    for(i=1;i<=n1;i++){
        L[i] = A[p+i-1];
    }
    for(j=1;j<=n2;j++){
        R[j] =  A[q+j];
    }
    L[n1+1] = INT_MAX;
    R[n2+1] = INT_MAX;
    i=1;
    j=1;
    for(int k=p;k<=r;k++){
        if(L[i]<=R[j]){
            A[k] = L[i];
            i = i+1;
        }
        else{
            A[k] = R[j];
            j = j+1;
        }
    }
}

void merge_sort(vector<int>&A,int p,int r){
    //vector<int>arr;
    if(p<r){
        int q = floor((p+r)/2);
        merge_sort(A,p,q);
        merge_sort(A,q+1,r);
        Merge(A,p,q,r);
    }
}

int main()
{
    cout<<"Enter length of array : ";
    int n;
    cin>>n;
    vector<int>arr;
    cout<<endl<<"Enter array elements : ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<endl;
   
    print_array(arr,arr.size());
    cout<<endl;
    
    merge_sort(arr,0,n-1);
    
    print_array(arr,arr.size());
    cout<<endl;
    return 0;
}
