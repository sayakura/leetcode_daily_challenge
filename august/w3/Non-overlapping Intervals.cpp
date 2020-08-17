class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;
        const int n = intervals.size();
        if (n == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), [](auto &a, auto&b) {
            return a[1] < b[1];            
        });
        vector<int> top = intervals[0];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < top[1]) cnt++;
            else top = intervals[i];
        }
        return cnt;
    }
};