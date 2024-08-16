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
    void reorderList(ListNode* head) {
        ListNode *headRev = nullptr, *tailRev = nullptr, *h2 = head;
        int size = 0;
        while(h2 != nullptr){
            if(headRev == nullptr){
                headRev = new ListNode(h2->val);
                tailRev = headRev;
            }
            else {
                headRev = new ListNode(h2->val, tailRev);
                tailRev = headRev;
            }
            
            size++;
            h2 = h2->next;
        }
        
        ListNode *newHead = nullptr, *newTail = nullptr;
        bool takingFront = true;

        h2 = head;

        for(int i=0; i<size; i++){
            if(takingFront){
                if(newHead == nullptr){
                    newHead = h2;
                    newTail = h2;
                }
                else {
                    newTail->next = h2;
                    newTail = h2;
                }
                h2 = h2->next;
            }
            else {
                newTail->next = headRev;
                newTail = headRev;
                
                headRev = headRev->next;
            }
            
            takingFront = !takingFront;
        }
        
        newTail->next = nullptr;
        
        head = newHead;

    }
};