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
    int deepestLeavesSum(TreeNode* root) {
        int depth = get_depth(root);
        int ans = 0;
        // cout << depth;
        
        add_ans(root, 1, depth, ans);
        
        return ans;
        
    }
    
    void add_ans(TreeNode* root, int curr_depth, int act_depth, int& ans){
        if(root == nullptr) return;
        
        if(curr_depth == act_depth){
            ans += root->val;
            return;
        }
        
        
        
        curr_depth++;
        
        add_ans(root->left, curr_depth, act_depth, ans);
        add_ans(root->right, curr_depth, act_depth, ans);     
    }
    
    
    int get_depth(TreeNode* root){
        if(root == nullptr)return 0;
        return max(get_depth(root->left), get_depth(root->right)) + 1;
    }
};