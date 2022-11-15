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
    int countNodes(TreeNode* root) {
        int count = 0;
        count_helper(root, &count);
        return count;
    }
    
    void count_helper(TreeNode* root, int* count){
        if(root == nullptr){
            return;
        }
        *count += 1;
        
        if(root->left !=nullptr){
            count_helper(root->left, count);
        }
        if(root->right !=nullptr){
            count_helper(root->right, count);
        }
    }
};