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
    int pre = 0; 
    unordered_map<int,int> freq;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0;i<inorder.size();i++)freq[inorder[i]] = i;
        return build(preorder,inorder,0,inorder.size()-1);
    }
    TreeNode* build(vector<int> preorder,vector<int> inorder,int l,int r)
    {
        if(l>r)return nullptr;
        TreeNode* root = new TreeNode(preorder[pre]);
        int mid = freq[preorder[pre++]];
        root->left = build(preorder,inorder,l,mid-1);
        root->right = build(preorder,inorder,mid+1,r);
        return root;
    }
};
