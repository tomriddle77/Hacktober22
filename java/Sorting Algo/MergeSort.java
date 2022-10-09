import java.util.*;
import java.lang.*;
import java.io.*;
class MergeSort {
	static int n1 = 0,n2=1,n3=0;
	public static void main(String[] args){
		int[] arr = {7,2,4,1,5,3};
		mergeSort(arr);
		for(int i : arr){
			System.out.print(i+" ");
		}
	}
	public static void mergeSort(int[] arr){
		int n = arr.length;
		if(n<2){
			return;
		}
		int mid = n/2;
		int[] left = new int[mid];
		int[] right = new int[n-mid];

		for(int i=0;i<mid;i++){
			left[i] = arr[i];
		}

		for(int i=mid;i<n;i++){
			right[i-mid] = arr[i];
		}

		mergeSort(left);
		mergeSort(right);
		merge(left,right,arr);
	}

	public static void merge(int[] left,int[] right,int[] arr){
		int i = 0;
		int j = 0;
		int k = 0;
		while(i<left.length && j<right.length){
			if(left[i]<right[j]){
				arr[k] = left[i];
				i++;
			}else{
				arr[k] = right[j];
				j++;
			}
			k++;
		}
		while(i!=left.length){
			arr[k] = left[i];
			i++;
			k++;
		}
		while(j!=right.length){
			arr[k] = right[j];
			j++;
			k++;
		}
	}
}
