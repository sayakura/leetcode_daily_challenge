class Solution {
public:
/*    bool isPalindrome(string s) {
        vector<char> t;
        for (char c : s) {
            if (isalnum(c))
                t.push_back(tolower(c));
        }
        for (int i = 0, j = t.size() - 1; i <= j; i++, j--) {
            if (t[i] != t[j])
                return false;
        }
        return true;
    }
*/
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (isalnum(s[left]) && isalnum(s[right])) {
                if (tolower(s[left]) != tolower(s[right]))
                    return false;
                left++; right--;
            } else if (!isalnum(s[left]))
                left++;
            else 
                right--;
        }
        return true;
    }
};