// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3377/

class Solution {
public:
    int arrangeCoins(int n) {
        if (n == 0 || n == 1)
            return n;
        long long last = 0;
        int i = 1;
        for (; i <= n; i++) {
            last = last + i;
            if (last > n)
                return i - 1;
        }
    UNREACHABLE: 
        return 77777777; 
    }
};