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
    pair<bool, pair<int, int>> isValidBSTHelper(TreeNode *root){
        if(root == nullptr){
            return make_pair(true, make_pair(INT_MAX, INT_MIN));
        }
        
        if(root->left == nullptr && root->right == nullptr){
            return make_pair(true, make_pair(root->val, root->val));
        }
        
        if(root->left == nullptr){
            pair<bool, pair<int, int>> right = isValidBSTHelper(root->right);
            if(right.first && root->val < right.second.first){
                return make_pair(
                    true, 
                    make_pair(
                        min(root->val, right.second.first), 
                        max(root->val, right.second.second)
                    )
                );
            }
            else {
                return make_pair(false, make_pair(0, 0));
            }
        }
        
        if(root->right == nullptr){
            pair<bool, pair<int, int>> left = isValidBSTHelper(root->left);
            if(left.first && root->val > left.second.second){
                return make_pair(
                    true, 
                    make_pair(
                        min(root->val, left.second.first), 
                        max(root->val, left.second.second)
                    )
                );
            }
            else {
                return make_pair(false, make_pair(0, 0));
            }
        }
        
        pair<bool, pair<int, int>> left = isValidBSTHelper(root->left);
        pair<bool, pair<int, int>> right = isValidBSTHelper(root->right);
        
        if(left.first && right.first && root->val > left.second.second && root->val < right.second.first){
            int minn = min(root->val, min(left.second.first, right.second.first));
            int maxx = max(root->val, max(left.second.second, right.second.second));
            
            // cout << minn << " , " << maxx << endl;
            
            return make_pair(true, make_pair(minn, maxx));
        }
        return make_pair(false, make_pair(0, 0));
    }
    
    
public:
    bool isValidBST(TreeNode* root) {
        pair<bool, pair<int, int>> ret = isValidBSTHelper(root);
        return ret.first;
    }
};