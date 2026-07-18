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
    unordered_map<int,int> index;
    int pre = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0;i<inorder.size();i++)index[inorder[i]] = i;
        return build(preorder,0,inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder,int li,int ri)
    {
        if (li > ri) return nullptr;
        TreeNode* n = new TreeNode(preorder[pre++]);
        int mid = index[n->val];
        n->left = build(preorder,li,mid-1);
        n->right = build(preorder,mid+1,ri);
        return n;
    }
};
