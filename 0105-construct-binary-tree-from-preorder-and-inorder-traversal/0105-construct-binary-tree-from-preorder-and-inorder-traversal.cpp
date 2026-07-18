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
        if(preorder.empty() || inorder.empty())return nullptr;
        TreeNode* n = new TreeNode(preorder[0]);
        auto it = find(inorder.begin(),inorder.end(),n->val);
        int mid = distance(inorder.begin(),it);
        if(mid != 0)
        {
            vector<int> left_pre(make_move_iterator(preorder.begin()+1),make_move_iterator(preorder.begin()+1+mid));
            vector<int> left_in(make_move_iterator(inorder.begin()),make_move_iterator(inorder.begin()+mid));
            n->left = buildTree(left_pre,left_in);
        }
        if(mid != preorder.size()-1)
        {
            vector<int> right_pre(make_move_iterator(preorder.begin()+1+mid),make_move_iterator(preorder.end()));
            vector<int> right_in(make_move_iterator(inorder.begin()+mid+1),make_move_iterator(inorder.end()));
            n->right = buildTree(right_pre,right_in);
        }
        return n;
    }
};
