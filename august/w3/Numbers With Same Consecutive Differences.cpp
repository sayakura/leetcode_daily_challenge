class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        if (N == 1)
            return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> ret;
        dfs(N, K, 0, ret);
        return ret;
    }
    void dfs(int n, int k, int cur, vector<int> &ret) {
        if (cur > (int)pow(10, n))
            return ;
        if (cur >= (int)pow(10, n - 1)) {
            ret.push_back(cur);
            return ;
        }
        for (int i = cur == 0 ? 1 : 0; i <= 9; i++) {
            if (cur == 0 || abs((cur % 10) - i) == k) {
                dfs(n, k, cur * 10 + i, ret);
            }
        }
    }
};