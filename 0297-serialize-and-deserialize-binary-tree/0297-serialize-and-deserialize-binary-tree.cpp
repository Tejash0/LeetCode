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

class Codec {
public:
    vector<int> help;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       if(!root)return "";
       queue<TreeNode*> q;
       string s;
       q.push(root);
       while(!q.empty())
       {
            TreeNode* x = q.front();
            q.pop();
            if(!x) s.append("#,");
            else
            {
                s.append(to_string(x->val)+",");
            }
            if(x!=nullptr)
            {
                q.push(x->left);
                q.push(x->right);
            }
       }
       return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())return nullptr;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode *x = q.front();
            q.pop();
            getline(s,str,',');
            if(str != "#")
            {
                TreeNode* l = new TreeNode(stoi(str));
                x->left = l;
                q.push(l);
            }
            getline(s,str,',');
            if(str != "#")
            {
                TreeNode* r = new TreeNode(stoi(str));
                x->right = r;
                q.push(r);
            }
        }
        return root;
    }
};
