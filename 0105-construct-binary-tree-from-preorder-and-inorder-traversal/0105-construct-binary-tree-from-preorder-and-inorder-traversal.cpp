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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int p = 0;
        int in_d = 0;
        return build(preorder,inorder,p,in_d,INT_MAX);
    }
    TreeNode* build(const vector<int>& preorder,const vector<int>& inorder,int& p,int& in_d,int s)
    {
        if (p >= preorder.size() || in_d >= inorder.size()) return nullptr;
        if(inorder[in_d] == s)
        {
            in_d++;
            return nullptr;
        }
        TreeNode* n = new TreeNode(preorder[p++]);
        n->left = build(preorder,inorder,p,in_d,n->val);
        n->right = build(preorder,inorder,p,in_d,s);
        return n;
    }
};
