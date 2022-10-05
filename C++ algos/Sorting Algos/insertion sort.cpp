#include<iostream>
using namespace std;
int main()
{
 string a;
 int n,i,j,temp;
 cout<<"Enter the string:";
cin>>a;
 n=a.length();
 for(i=0;i<n;i++)
 {
 for(j=0;j<n;j++)
 {
 if(a[j]>a[j+1])
 {
 temp=a[j];
 a[j]=a[j+1];
 a[j+1]=temp;
 }
 }
 }
 cout<<"sorted string:";
 for(i=0;i<=n;i++)
 cout<<a[i]<<" ";
 return 0;
}
