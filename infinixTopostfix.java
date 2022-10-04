
import java.util.Scanner;
import java.util.Stack;

public class infinixTopostfix {
    public static void main(String[] args) {
        Scanner s =new Scanner(System.in);
        String infinix=s.nextLine();
        // String infinix="(A+B)*(C/D)";
        System.out.println(postfix(infinix));
    }
    public static int prec(char c)
    {
        // Multiplication and division
        if (c == '*' || c == '/') {
            return 3;
        }
 
        // Addition and subtraction
        if (c == '+' || c == '-') {
            return 4;
        }
 
        // Bitwise AND
        if (c == '&') {
            return 8;
        }
 
        // Bitwise XOR (exclusive or)
        if (c == '^') {
            return 9;
        }
 
        // Bitwise OR (inclusive or)
        if (c == '|') {
            return 10;
        }
 
        // add more operators if needed
 
        return Integer.MAX_VALUE;            // for opening bracket '('
    }
 
    // Utility function to check if a given token is an operand
    public static boolean isOperand(char c)
    {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9');
    }
 
    
   
    public static String postfix(String infinix)
    {
        Stack<Character> st=new Stack<>();
        String ans="";
        for (int i = 0; i < infinix.length(); i++) {
            char ch=infinix.charAt(i);
            if (ch=='(') {
                st.push(ch);
            }
            else if(isOperand(ch))  ans+=ch;

            else if(ch==')') {
                while(st.peek()!='(')
                {
                    ans+=st.pop();    
                }
                st.pop();
            }
            else{
                while(!st.isEmpty()  && prec(ch)>=prec(st.peek()))
                {
                    ans+=st.pop();
                }
                st.push(ch);
            }
            
        }
        while(!st.isEmpty())
        {
            ans+=st.pop();
        }
        return ans;
    }
}
        