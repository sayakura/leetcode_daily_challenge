// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3382/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        digits[digits.size() - 1]++;
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] = digits[i] % 10;
        }
        if (carry)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};