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
    void dfs(TreeNode *node, vector<int> &list)
    {
        if(node==nullptr)
            return;
        dfs(node->left, list);
        list.push_back(node->val);
        dfs(node->right, list);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1;
        vector<int> list2;
        dfs(root1, list1);
        dfs(root2, list2);
        auto p1 = list1.begin();
        auto p2 = list2.begin();
        vector<int> ret;
        while(1)
        {
            if(p1==list1.end())
            {
                ret.insert(ret.end(), p2, list2.end());
                break;
            }
            if(p2==list2.end())
            {
                ret.insert(ret.end(), p1, list1.end());
                break;
            }
            if(*p1 < *p2)
            {
                ret.push_back(*p1);
                ++p1;
            }
            else
            {
                ret.push_back(*p2);
                ++p2;
            }
        }
        return ret;
    }
};
