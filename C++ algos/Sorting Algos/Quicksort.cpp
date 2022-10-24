#include<iostream>
#include<iomanip>

using namespace std;

int partition(int arr[],int s,int e)
{
 int pivot=arr[e];
 int pindex=s;
 for(int i=s;i<e;i++)
 {
  if(arr[i]<pivot)
  {
   arr[pindex]=arr[i];
   pindex++;
   }
 }
return pindex;
}

void quicksort(int arr,int s,int e)
{
 int p=partition(arr,s,e);
 quicksort(arr,s,(p-1));
 quicksort(arr,(p+1),e);
}

int main()
{
 int arr[],n;
  cout<<"enter the number of elements to be sorted"<<endl;
  cin>>n;
 cout<<"enter"<<n<<"elements"<<endl;
for(int i=0;i<n;i++)
 {
  cin>>arr[i];
 }

quicksort(arr,0,n);

for(int i=0;i<n;i++)
{
 cout<<arr[i]<<endl;
}
return 0;
}
