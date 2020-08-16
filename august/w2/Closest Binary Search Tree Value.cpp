class Solution {
public:
    double gap = DBL_MAX;
    int ret;
    void dfs(TreeNode *root, double target) {
        if (!root)
            return ;
        if (abs(root->val - target) < gap) {
            ret = root->val;
            gap = abs(root->val - target);
        }
        if (target < root->val) 
            dfs(root->left, target);
        else 
            dfs(root->right, target);
    }
    int closestValue(TreeNode* root, double target) {
        dfs(root, target);
        return ret;
    }
};