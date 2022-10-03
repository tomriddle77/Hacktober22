import java.util.*;

public class LinearSearch {

    public static int linear_search(int arr[], int no) {
        int arr_len = arr.length;

        for (int i = 0; i < arr_len; i++) {
            if (arr[i] == no)
                return i;
        }

        return -1;

    }

    public static void main(String args[]) {
        int arr[] = { 35, 33, 1, 2, -9, 8, 522 };
        int n = 35;
        int res = linear_search(arr, n);
        if (res != -1)
            System.out.println("Number found at index : " + res);
        else
            System.out.println("Number not found");

        // Time Complexity : O(n) where n is the number of elements in the array

    }
}