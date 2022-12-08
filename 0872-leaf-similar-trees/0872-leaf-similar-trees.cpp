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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1, l2;
        get_leaves(root1, l1);
        get_leaves(root2, l2);
        
        // print(l1);
        // print(l2);
        
        return l1 == l2;
    }
    
    void get_leaves(TreeNode* root, vector<int>& v){
        if(root->left == nullptr && root->right == nullptr){
            v.push_back(root->val);
            return;
        }
        if(root->left != nullptr){
            get_leaves(root->left, v);
        }
        if(root->right != nullptr){
            get_leaves(root->right, v);
        }    
        return;
    }
    
    void print(const vector<int> &vect) { 
        // vect.push_back(30);   // Uncommenting this line would 
                                // below error 
        // "prog.cpp: In function 'void func(const std::vector<int>&)': 
        // prog.cpp:9:18: error: passing 'const std::vector<int>' 
        // as 'this' argument discards qualifiers [-fpermissive]" 

        for (int i = 0; i < vect.size(); i++) 
        cout << vect[i] << " "; 
        cout << endl;
    } 
};