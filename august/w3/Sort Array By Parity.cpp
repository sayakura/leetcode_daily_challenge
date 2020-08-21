class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int front = 0;
        int back = A.size() - 1;
        while (front < back) {
            while (front < back && A[front] % 2 == 0) front++;
            while (front < back && A[back] % 2 == 1) back--;
            swap(A[front], A[back]);            
        }
        return A;
    }
};