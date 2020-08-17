class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int t1c = INT_MAX, t2c = INT_MAX;
        int t1p = 0, t2p = 0;
        
        for (int p : prices) {
            t1c = min(t1c, p); 
            t1p = max(t1p, p - t1c);
            t2c = min(t2c, p - t1p);
            t2p = max(t2p, p - t2c);
        }
        return t2p;
    }
};
