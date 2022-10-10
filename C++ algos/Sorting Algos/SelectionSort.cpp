#include<iostream>
using namespace std;
void selectionSort(int a[],int size){
for(int i=0;i<size-1;i++){
    int min=i;
    for(int j=i+1;j<size;j++){
        if(a[j]<a[min]){
            min=j;
        }
    }
    if(min!=i){
        int temp = a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}
for(int i=0;i<size;i++){cout<<a[i]<<" ";}
}
using namespace std;
int main()
{
 int a[]={4,2,1,0,3};
 int size=sizeof(a)/sizeof(a[0]);
 selectionSort(a,size);
 return 0;
}
