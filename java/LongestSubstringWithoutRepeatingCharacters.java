
import java.util.HashMap;

/*
Given a string s, find the length of the longest substring without repeating characters.



Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.



Constraints:

    0 <= s.length <= 5 * 104
    s consists of English letters, digits, symbols and spaces.


 */
public class LongestSubstringWithoutRepeatingCharacters {

    public static void main(String[] args) {
        String s="abcabcbb";
       int ans = lengthOfLongestSubstring(s);
        System.out.println(ans);
    }

    public static int lengthOfLongestSubstring(String s) {
        HashMap<Character,Integer> map = new HashMap<>(); // storing character & corresponding index
        int ans=0;
        for (int i=0,j=0;j<s.length();j++){
            char ch = s.charAt(j);
            if (map.containsKey(ch))
                // find max index
                i = Math.max(i, map.get(ch));

            ans = Math.max(ans, j-i+1);  // j-i+1 length of string
            map.put(ch,j+1);
        }
        return ans;
    }

}
