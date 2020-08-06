class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<bool> mp(nums.size(), false);
        vector<int> ret;
        for (int n : nums) {
            if (mp[n])
                ret.push_back(n);
            else
                mp[n] = true;
        }
        return ret;
    }
};