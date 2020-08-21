class Solution {
public:
    vector<int> distributeCandies(int candies, int n) {
        vector<int> ret(n, 0);
        int i = 1;
        int idx = 0;
        while (candies) {
            ret[idx] += min(candies, i);
            candies -= min(candies, i);
            i++;
            idx = (idx + 1) % n;
        }
        return ret;
    }
};