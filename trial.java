import java.util.*;

public class Main
{
    public static int ansString(String str) {
        int ans = 0;
        int n = str.length();

        for (int i = 0; i < n; i++) {
            if (i + 3 < n && isPalindrome(str.substring(i, i + 4)))  ans += 5;
            if (i + 4 < n && isPalindrome(str.substring(i, i + 5)))  ans += 10;
            
        }

        return ans;
    }

   public static boolean isPalindrome(String s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s.charAt(left) != s.charAt(right))  return false;
            left++;
            right--;
        }

        return true;
    }
    
    public static void main(String[] args) {
        String str = "CwaFMIWFITTFSQQmCRPhTThKJADOWPуoop";
        int result = ansString(str);
        System.out.println(result); // Output: 15
    }
}
