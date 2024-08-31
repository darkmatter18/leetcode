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
    void findMax(TreeNode* root, int maxTillNow, int &maxNum){
        if(root == nullptr) return;
        
        if(root->val >= maxTillNow){
            maxNum++;
        }
        maxTillNow = max(maxTillNow, root->val);
        
        findMax(root->left, maxTillNow, maxNum);
        findMax(root->right, maxTillNow, maxNum);
        
    }
    
public:
    int goodNodes(TreeNode* root) {
        int maxNum = 0;
        findMax(root, INT_MIN, maxNum);
        return maxNum;
    }
};