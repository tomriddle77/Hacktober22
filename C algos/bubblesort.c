#include <stdio.h>

int main(){

int arr[7];
int f=0,l=6,s=6,n;
    int mid = (f+l)/2;//3

    for(int i=0;i<7;i++){
    printf("Enter number %d: ",i+1);
    scanf("%d",&arr[i]);

    }
printf("Enter searching number:");
scanf("%d",&s);



for(int i=0;i<7;i++){

    if(s==arr[mid]){
        printf("number is found at index %d",mid);
        break;
    }else if(s>arr[mid]){
        f=mid+1;
        mid=(f+l)/2;
    }else if(s<arr[mid]){
        l=mid-1;
        mid=(f+l)/2;
    }


}



return 0;
}
