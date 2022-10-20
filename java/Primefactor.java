import java.io.*;
import java.util.Scanner;
class Primefactor
{
		public static int prime(int a)		
		{
			int c=0;
			for(int i=2;i<=Math.sqrt(a);i++)
			{
				if(a%i==0)
				{
					c++;
					break;
				}
			}
			if(c==0)
				return a;
		}

		public static void main(String[] args)
		{
			Scanner sc=new Scanner(System.in);
			System.out.println("Enter the number:- ");
			int x=sc.nextInt();
			
			System.out.println("Prime factors are ");
			for(int i=0;i<=x;i++)
			{
				if(x%i==0)
				{
					prime(i);
					System.out.println(i);
				}
			}
		}
}