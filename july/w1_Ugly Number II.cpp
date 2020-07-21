// link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3380/

class Solution {
public:
    int dp[1691];
    Solution() {
        int i = 1;
        int n2i, n3i, n5i;
        n2i = n3i = n5i = 0;
        dp[0] = 1;
        for (int i = 1; i <= 1690; i++) {
            int n2 = dp[n2i] * 2;
            int n3 = dp[n3i] * 3;
            int n5 = dp[n5i] * 5;
            int u = min({n2, n3, n5});
            dp[i] = u;
            if (u == n2) n2i++;
            if (u == n3) n3i++;
            if (u == n5) n5i++;
        }
    }
    int nthUglyNumber(int n) {
        return dp[n - 1];
    }
};