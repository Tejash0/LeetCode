/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool check = true;
    bool isBalanced(TreeNode* root) {      
        x(root);
        if(!check)
            return false;
        return true;
    }
    int x(TreeNode* m)
    {
        if(!m)return 0;
        int l = x(m->left);
        int r = x(m->right);
        if(abs(l-r) > 1)check = false;
        return 1 + max(l,r);
    }
};
