#include<iostream>
using namespace std;
 
int findSmallest (int[],int);
int main ()
{
   int myarray[5] = {12,45,8,15,33};
   int pos,temp;
   cout<<"\n Input list of elements to be Sorted\n";
   for(int i=0;i<5;i++)
   {
      cout<<myarray[i]<<"\t";
   }
   for(int i=0;i<5;i++)
   {
      pos = findSmallest (myarray,i);
      temp = myarray[i];
      myarray[i]=myarray[pos];
      myarray[pos] = temp;
   }
   cout<<"\n Sorted list of elements is\n";
   for(int i=0;i<5;i++)
   {
      cout<<myarray[i]<<"\t";
   }
return 0;
}
int findSmallest(int myarray[],int i)
{
   int ele_small,position,j;
   ele_small = myarray[i];
   position = i;
   for(j=i+1;j<5;j++)
   {
      if(myarray[j]<ele_small)
      {
      ele_small = myarray[j];
      position=j;
      }
   }
   return position;
}
