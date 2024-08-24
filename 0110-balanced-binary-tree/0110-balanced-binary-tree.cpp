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
    pair<bool, int> recursive(TreeNode *root){
        if(root == nullptr) return make_pair(true, 0);
        
        pair<bool, int> left = recursive(root->left);
        pair<bool, int> right = recursive(root->right);

        if(left.first && right.first && abs(left.second-right.second) <= 1){
            return make_pair(true, max(left.second, right.second)+1);
        }
        else {
            return make_pair(false, max(left.second, right.second)+1);
        }
    }
    
    
    
public:
    bool isBalanced(TreeNode* root) {
        pair<bool, int> res = recursive(root);
        return res.first;
    }
};