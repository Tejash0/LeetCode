class Solution {
public:
    int m = -1; 
    int count = 0;
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        kthSmallest(root->left, k);
        count++;
        if (count == k)m = root->val;
        if (count < k)kthSmallest(root->right, k);
        return m;
    }
};