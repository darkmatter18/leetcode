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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0, front;
        ListNode* no = head, n1;
        while(no != nullptr){
            size++;
            no = no->next;
        }
        cout << size;
        front = size - n;
        int x = front - 1, y = front - 1;
        
        no = head;
        
        while(x > 0){
            no = no->next;
            x--;
        }
        
        cout << no->val;
        if(y < 0){
            head = no->next;
        } else {
            no->next = no->next->next;    
        }
        
        
        return head;
    }
};