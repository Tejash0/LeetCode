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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        path(root,maxi);
        return maxi;
    }
    int path(TreeNode*& root,int& maxi)
    {
        if(!root)return 0;
        int maxl = max(0,path(root->left,maxi));
        int maxr = max(0,path(root->right,maxi));
        maxi = max(maxi,(maxl+maxr+root->val));
        return root->val + max(maxl,maxr);
    }
};