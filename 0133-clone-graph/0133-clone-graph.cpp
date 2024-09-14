/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* clone(Node* node, unordered_map<int, Node *>& visited_set){
        if(node == nullptr) return nullptr;
        
        if(visited_set.find(node->val) != visited_set.end()){
            return visited_set[node->val];
        }
        
        // cout << node->val << endl;
        
        Node* new_node = new Node(node->val);
        visited_set[node->val] = new_node;
        
        for(Node* neighbor : node->neighbors){
            new_node->neighbors.push_back(clone(neighbor, visited_set));
        }
        
        
        return new_node;
    }
    
    
public:
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node *> visited_set;
        
        return clone(node, visited_set);
    }
};