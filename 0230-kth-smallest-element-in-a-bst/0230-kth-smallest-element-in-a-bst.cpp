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
private:
    int ans = INT_MIN, _k;

    void recursive(TreeNode *root){
        if(root == nullptr) return;
        
        recursive(root->left);
        if(_k-1 == 0){
            ans = root->val;
        }
        _k--;
        recursive(root->right);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        _k = k;
        recursive(root);
        
        return ans;
    }
};