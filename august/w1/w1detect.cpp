class Solution {
public:
    bool isSame(string word, bool low, int j) {
        for (int i = j; i < word.size(); i++) {
            if (low && !islower(word[i]))
                return false;
            if (!low && !isupper(word[i]))
                return false;
        }
        return true;
    }
    bool detectCapitalUse(string word) {
        bool isCap = isupper(word[0]);
        if (word.size() == 1) 
            return true;
        return ((isCap && isSame(word, true, 1)
            ||
            (isSame(word, false, 0)))
            ||
            (isSame(word, true, 0)));
    }
};