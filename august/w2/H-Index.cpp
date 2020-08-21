class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> count(n + 1, 0);
        for (int c : citations) 
             count[min(c, n)]++;
        int s = n;
        for (int i = count[n]; s > i; i += count[s])
            s--;
        return s;
    }
};