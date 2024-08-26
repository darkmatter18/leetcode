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
    bool isSimiler(TreeNode* root1, TreeNode* root2){
        if(root1==nullptr && root2==nullptr) return true;
        if(root1==nullptr || root2==nullptr) return false;
        
        if(root1->val != root2->val) return false;
        
        return isSimiler(root1->left, root2->left) && isSimiler(root1->right, root2->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr){
            return false;
        }
        bool ans = false;
        if(root->val == subRoot->val){
            // check for similaritiy
            ans = isSimiler(root, subRoot);
        }
        if(ans) return true;
        
        ans = isSubtree(root->left, subRoot);
        if(ans) return true;
        
        ans = isSubtree(root->right, subRoot);
        if(ans) return true;
        
        return false;
    }
};