/*
the logic behind sort： a[0] - a[1] -> calculate the profit of going to city A (a[0]) instead of city B (a[1])
                        and compare it with b[0] - b[1]
we can prioritize options that favor city A first (I use < in the sort lambda, smaller number will be prioritized) 
in the contrast, options that favor city A least means that it favors city B, we send the rest to city B cost (half:]

if the input is [10,20],[30,200],[400,50],[30,20]
we got the sorted array: 
    (30 , 200) -> -170 (a[0] - a[1]) we save 170 if we go to city A
    (10 , 20) -> -10
    - - - - - - - - -
    (30 , 20) -> 10 
    (400 , 50) -> 350
*/  

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size(), half = n / 2;
        int ret = 0;
        sort(costs.begin(), costs.end(), [](auto &a, auto &b) {
            return (a[0] - a[1]) < (b[0] - b[1]);
        });
        for (int i = 0; i < half; ++i) 
            ret += costs[i][0] + costs[n - i - 1][1];
        return ret;
    }
};