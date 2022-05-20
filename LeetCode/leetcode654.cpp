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

    TreeNode *dfs(vector<int> &nums, int start, int end)
    {
        if(start>end || start<0 || end>=nums.size())
            return nullptr;
        int maxV = nums[start];
        int index = start;
        for(int i=start; i<=end; ++i)
        {
            if(nums[i] > maxV)
            {
                index = i;
                maxV = nums[i];
            }
        }
        TreeNode *root = new TreeNode(nums[index]);
        if(index==start)
            root->left = nullptr;
        else
            root->left = dfs(nums, start, index-1);
        if(index==end)
            root->right = nullptr;
        else
            root->right = dfs(nums, index+1, end);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int len = nums.size();
        return dfs(nums, 0, len-1);
    }
};
