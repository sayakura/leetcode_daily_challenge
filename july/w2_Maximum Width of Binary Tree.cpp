// https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/545/week-2-july-8th-july-14th/3385/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode *, int>> q;
        unsigned long long width = 0;
        
        q.push({ root, 1 });
        while (!q.empty()) {
            unsigned long long l = q.front().second;
            unsigned long long r = 0;
            for (int i = 0, siz = q.size(); i < siz; i++) {
                auto front = q.front(); q.pop();
                auto curNode = front.first; 
                r = front.second;
                if (curNode->left)  q.push({ curNode->left, r * 2 });
                if (curNode->right) q.push({ curNode->right, r * 2 + 1 });
            }
            width = max(width, r - l + 1);
        }
        return width;
    }
};