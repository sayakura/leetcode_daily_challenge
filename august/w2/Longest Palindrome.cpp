class Solution {
public
    int longestPalindrome(string s) {
        char arr[127] = { 0 };
        int ret = 0;
        bool hasOdd = false;
        for (char c : s) 
            arr[(int)c]++;
        for (int i = 0; i < 127; i++) {
            if (arr[i] & 1)
                hasOdd = true;
            ret += (arr[i] / 2) * 2;
        }
        return hasOdd ? ret + 1 : ret;
    }
};