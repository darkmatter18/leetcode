/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *newNode = new ListNode();
        ListNode *head = new ListNode();
        head = newNode;
        
        bool extraCarry = false;
        
        while(l1 != nullptr || l2 != nullptr){
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            
            int s = a + b;
            if(extraCarry){
                s += 1;
            }
            cout << "S is " << s;
            if(s >= 10){
                extraCarry = true;
                cout << "carry";
                s -= 10;
                cout << s;
            } else {
                extraCarry = false;
            }
            ListNode *l = new ListNode(s);
            newNode->next = l;
            newNode = l;
            
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        if(extraCarry){
            ListNode *l = new ListNode(1);
            newNode->next = l;
            newNode = l;
        }
        
        return head->next;
    }
};