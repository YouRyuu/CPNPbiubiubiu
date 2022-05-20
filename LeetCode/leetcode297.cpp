/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "#";
        string val = to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
        return val;
    }

    TreeNode *dfs(string data, int *index, int len)
    {
        if(*index >= len)
            return NULL;
        if(data[*index]==',')
            ++(*index);
        if(data[*index]=='#')
        {
            ++(*index);
            return NULL;
        }
        string val;
        while(data[*index]!=',')
        {
            val += data[*index];
            ++(*index);
        }
        TreeNode *root = new TreeNode(stoi(val));
        root->left = dfs(data, index, len);
        root->right = dfs(data, index, len);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int len = data.size();
        int index = 0;
        return dfs(data, &index, len);
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
