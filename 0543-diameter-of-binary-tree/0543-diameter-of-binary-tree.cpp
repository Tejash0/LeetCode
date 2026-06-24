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
    int diam = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dd(root);
        return diam;
    }
    int dd(TreeNode* n)
    {
        if(!n)
            return 0;
        int l = dd(n->left);
        int r = dd(n->right);
        diam = max(diam, l+r);
        return 1+max(l,r);
    }
};
