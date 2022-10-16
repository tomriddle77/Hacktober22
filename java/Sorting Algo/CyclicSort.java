import java.util.Arrays;

public class CyclicSort 
{
    
    /** 
    @Cyclic Sort:
        - Time Complexity - O(N^2)
        - Space Complexity - O(1)
    **/
    static void cyclicSort(int[] arr){
        int i = 0;
        while (i < arr.length) {
            int correct = arr[i] - 1; //correct position is value -1 (i.e. arr[i] - 1)
            if(arr[i] != arr[correct]){
                swap(arr, i, correct); // swapping the position with correct position
            } else {
                i++;
            }
        }
    }

    // For swapping numbers
    static void swap(int[] arr, int first, int second){
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
  
    void print(int arr[])
    {
        for (int i = 0; i < arr.length; i++)
            System.out.print(arr[i] + " ");
        System.out.println();
    }
  
    public static void main(String args[])
    {
        int arr[] = { 5, 4, 2, 1, 3 };
        cyclicSort(arr);
        System.out.println("Sorted array");
        System.out.println(Arrays.toString(arr));
    }
}