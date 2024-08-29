/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* bufferHead = head;
        map<Node*, Node*> oldToNew;
        
        while(bufferHead != nullptr){
            oldToNew[bufferHead] = new Node(bufferHead->val);
            bufferHead = bufferHead->next;
        }
        
        bufferHead = head;
        while(bufferHead != nullptr){
            oldToNew[bufferHead]->next = oldToNew[bufferHead->next];
            oldToNew[bufferHead]->random = oldToNew[bufferHead->random];
            
            bufferHead = bufferHead->next;
        }
        
        return oldToNew[head];
    }
};