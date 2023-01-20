/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* ans = nullptr;
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        inorder(original, cloned, target);
        // cout << " D " << ans;
        return ans;
    }
    
    void inorder(TreeNode* original, TreeNode* cloned, TreeNode* target){
        if(original == nullptr)
            return;
        
        // cout << original->val << "  ";
        
        inorder(original->left, cloned->left, target);
        
        if(original->val == target->val){
            ans = cloned;
            // cout << " BB " << target->val << "  " << cloned << " " << ans;
        }
        
        inorder(original->right, cloned->right, target);
    }
};