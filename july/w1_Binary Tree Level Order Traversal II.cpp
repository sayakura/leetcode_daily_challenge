// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3378/

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> ret;
        if (!root)
            return ret;
        
        while(!q.empty()) {
            vector<int> thisl;
            int siz = q.size();
            while (siz--) {
                auto top = q.front(); q.pop();
                thisl.push_back(top->val);
                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);
            }          
            ret.push_back(thisl);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};