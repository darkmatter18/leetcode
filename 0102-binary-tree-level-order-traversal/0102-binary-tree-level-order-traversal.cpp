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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == nullptr)
            return ret;
            
        queue<TreeNode*> q;
        q.push(root);
        
        int max_el = 1, next_max_el;
        
        vector<int> v;
        while(!q.empty()){
            next_max_el = max_el * 2;
            for(int i = 0; i < max_el; i++){
                TreeNode* el = q.front();
                q.pop();
                v.push_back(el->val);
               
                if(el->left == nullptr) next_max_el--;
                else q.push(el->left);
                
                if(el->right == nullptr) next_max_el--;
                else q.push(el->right);
            }
            max_el = next_max_el;
            ret.push_back(v);
            v.clear();
        }
        
        return ret;
    }
};