import java.util.*;
public class palindrome {
    public static void main(String args[])
    {
        String A;
        String B="";
        int l,i,mid,flag=-1;
        Scanner sc= new Scanner(System.in);
        System.out.println("enter the string");
        A=sc.nextLine();
        l=A.length();
        for(i=l-1;i>=0;i--)
            B=B+A.charAt(i);
        if(A.toLowerCase().equals(B.toLowerCase()))
              System.out.println("the string is a palindrome");
        else
                System.out.println("the string is not a palindrome");
    }            
}