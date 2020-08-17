class Solution {
public:
    vector<int> findPermutation(string s) {
        const int n = s.size();
        vector<int> ret(n + 1, 0);
        stack<int> st;
        int idx = 0;
        
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == 'I') {
                st.push(i);
                while (!st.empty()) {
                    ret[idx++] = st.top();
                    st.pop();
                }
            } else 
                st.push(i);
        }
        st.push(n + 1);
        while (!st.empty()) {
            ret[idx++] = st.top();
            st.pop();
        }
        return ret;
    }
};