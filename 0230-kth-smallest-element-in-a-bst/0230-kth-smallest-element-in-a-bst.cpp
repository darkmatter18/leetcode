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
    void recursive(TreeNode *root, vector<int> &res){
        if(root == nullptr) return;
        
        recursive(root->left, res);
        res.push_back(root->val);
        recursive(root->right, res);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> data;
        recursive(root, data);
        
        return data[k-1];
    }
};