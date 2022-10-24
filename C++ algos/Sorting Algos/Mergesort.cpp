#include<iostream>

using namespace std;

void  merge(int arr[],int l,int mid,int h)
{
 int b[5];
 int i=l;
 int k=l;
 int j=mid+1;
 while(i<=mid && j<=h)
 {
 if(arr[i]<arr[j])
 {
  b[k]=arr[i];
  k++;
  i++;
  }
  else
  {
   b[k]=arr[j];
   k++;
   j++;
   }
  }
  while(i<=mid)
  {
   b[k]=arr[j];
   k++;
  }
  while(j<=h)
  {
    b[k]=arr[i];
    k++;
   }
 for(int k=0;k<=h;k++)
 {
  arr[i]=b[k];
 }
}

void mergesort(int arr[],int l,int h)
{
 int mid=(l+h)/2;
 mergesort(arr,l,mid);
 mergesort(arr,(mid+1),h);
merge(arr,l,mid,h);
}

int main()
{
 int myarr[],n;
 cout<<"enter the number of elements"<<endl;
 cin>>n;
 cout<<"enter"<<n<<elements"<<endl;
 for(int i=0;i<n;i++)
 {
  cin>>myarr[i];
 }

 mergesort(myarr,0,(n-1));

for(int i=0;i<n;i++)
{
 cout<<myarr[i]<<endl;
}
return 0;
}
