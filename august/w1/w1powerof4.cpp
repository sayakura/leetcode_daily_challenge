class Solution {
public:
/*
    unordered_set<int> mp;
    Solution() {
        int n = 1;
        mp.insert(n);
        for (int i = 0; i < 15; i++) 
            mp.insert(n <<= 2);
    }
    bool isPowerOfFour(int num) {
        return mp.find(num) != mp.end();
    }
*/    

/*
    bool isPowerOfFour(int num) {
        return num > 0 && !(num & num - 1) && num & 0x55555555;
    }
*/ 
    bool isPowerOfFour(int num) {
        return __builtin_popcount(num) == 1 && (num & 0x55555555);
    }
};