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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return nullptr;
        
        if(preorder.size() == 1){
            return new TreeNode(preorder[0]);
        }
        
        int currRoot = preorder[0], leftLen=0;
        
        while(leftLen < inorder.size()){
            if(inorder[leftLen] == currRoot){
                break;
            }
            leftLen++;
        }
        
        vector<int> leftInorder(inorder.begin(), inorder.begin()+leftLen); // left inorder
        vector<int> leftPreorder(preorder.begin()+1, preorder.begin()+1+leftLen); // left preorder
        
        vector<int> rightInorder(inorder.begin()+leftLen+1, inorder.end()); // right inorder
        vector<int> rightPreorder(preorder.begin()+1+leftLen, preorder.end()); // right preorder
            
        TreeNode* left = buildTree(leftPreorder, leftInorder);
        TreeNode* right = buildTree(rightPreorder, rightInorder);
        
        return new TreeNode(currRoot, left, right);
    }
};