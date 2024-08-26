/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void recursion(Node *root, vector<int> &res){
        if(root == nullptr) return;
        
        for(Node* child : root->children){
            recursion(child, res);
        }
        res.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        recursion(root, res);
        
        return res;
    }
};