class Solution {
public:
    int ret;
    void helper(unordered_map<int, int> &s, TreeNode *root, int prefix, int sum) {
        if (!root)
            return ;
        prefix += root->val;
        if (prefix == sum)
            ret++;
        if (s.find(prefix - sum) != s.end())
            ret += s[prefix - sum];
        s[prefix]++;
        helper(s, root->left, prefix, sum);
        helper(s, root->right, prefix, sum);
        s[prefix]--;
    }
    int pathSum(TreeNode* root, int sum) {
        ret = 0;
        unordered_map<int, int> s;
        helper(s, root, 0, sum);        
        return ret;        
    }
};