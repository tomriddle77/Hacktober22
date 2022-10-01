#include<iostream>
using namespace std;
int sort(int  a[],int n)
{
    int min,i,j;
    for(i=0;i<n-1;i++)
    {
    min=a[i];
    int  x=i;  
    for(j=i+1;j<n;j++)
    {
        if(min>a[j])
        {
            min=a[j];
            x=j;
        }
    }
    ///swap
    int temp=a[i];
    a[i]=a[x];
    a[x]=temp;
    }

}
int main()
{
  int n,i;
  cin>>n;
  int a[n];
    cout<<"Enter Array-"<<endl;
  for(i=0;i<n;i++)
  {
    
      cin>>a[i];
  }
  sort(a,n);
    cout<<"sorted Array-"<<endl;

   for(i=0;i<n;i++)
  {
          

      cout<<a[i]<<endl;
  }

}