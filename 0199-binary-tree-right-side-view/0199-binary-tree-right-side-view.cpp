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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;
        
        int currLen = 1, nextLen;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            nextLen = 0;
            
            for(int i=0; i<currLen; i++){
                TreeNode* n = q.front();
                q.pop();
                if(n->left != nullptr){
                    q.push(n->left);
                    nextLen++;
                }
                if(n->right != nullptr){
                    q.push(n->right);
                    nextLen++;
                }
                if(i==currLen-1){
                    res.push_back(n->val);
                }
            }
            
            currLen = nextLen;
        }
        
        return res;
    }
};