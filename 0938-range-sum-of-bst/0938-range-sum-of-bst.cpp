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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int s = 0;
        rangeSumHandler(root, low, high, &s);
        return s;
    }
    void rangeSumHandler(TreeNode* root, int low, int high, int* s){
        if(root == nullptr) return;
        
        if(root->val >= low && root->val <= high){
            *s += root->val;
            // check both left and right
            rangeSumHandler(root->left, low, high, s);
            rangeSumHandler(root->right, low, high, s);
        } else if(root->val < low){
            // check only the right
            rangeSumHandler(root->right, low, high, s);
        } else if(root->val > high){
            // check only the left
            rangeSumHandler(root->left, low, high, s);
        } else return;
    }
};