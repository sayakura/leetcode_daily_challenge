class CombinationIterator {
public:
    int bit, n, k;
    string chars;
    CombinationIterator(string characters, int combinationLength) {
        n = characters.size();
        k = combinationLength;
        chars = characters;
        bit = (1 << n) - (1 << (n - k));
    }
    
    string next() {
        string ret = "";
        for (int i = 0; i < n; ++i) {
            if (bit & (1 << (n - i - 1))) {
                ret += chars[i];
            }
        }
        bit--;
        while (bit > 0 && __builtin_popcount(bit) != k)
                bit--;
        return ret;
    }
    
    bool hasNext() {
        return bit > 0;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */