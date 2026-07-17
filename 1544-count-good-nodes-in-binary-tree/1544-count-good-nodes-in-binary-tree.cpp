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
    int goodNodes(TreeNode* root) {
        return d(root,root->val);
    }
    int d(TreeNode* n,int m)
    {
        if(!n)return 0;
        int r = 0;
        if(m <= n->val)r++;
        m = max(m,n->val);
        r += d(n->left,m);
        r += d(n->right,m);
        return r;
    }
};
