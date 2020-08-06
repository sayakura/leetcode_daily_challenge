// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3384/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& A) {
        int n, a, b, c, sum, left, right;
        
        vector<vector<int>> res;
        sort(A.begin(), A.end());
        n = A.size();

        for (int i = 0; i < n; i++) {
            int target = -A[i];
            left = i + 1;
            right = n - 1;
            while (left < right) {
                sum = A[left] + A[right];
                if (sum < target)
                    left++;
                else if (sum > target)
                    right--;
                else {
                    a = A[i];
                    b = A[left];
                    c = A[right];
                    res.push_back({ a, b, c });
                    while (left < right && A[left] == a) left++;
                    while (left < right && A[right] == c) right--;
                }
            }
            while (i + 1 < n && A[i + 1] == A[i]) i++; 
        }
        return res;
    }
};

