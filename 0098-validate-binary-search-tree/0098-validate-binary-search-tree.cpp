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
    bool isValidBST(TreeNode* root) {
        return isBST(root,LONG_MIN,LONG_MAX);
    }

    bool isBST(TreeNode* n,long l,long h)
    {
        if(!n)return true;
        if(n->val >= h || n->val <= l)return false;
        return isBST(n->left,l,n->val) && isBST(n->right,n->val,h);
    }
};
