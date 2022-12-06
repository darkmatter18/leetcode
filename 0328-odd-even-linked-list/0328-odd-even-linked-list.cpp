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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* even = new ListNode(0);
        ListNode* odd = new ListNode(0);

        ListNode* odd_start = odd;
        ListNode* even_start = even;
        int c = 0;

        while(head != nullptr){
            if(c % 2 != 0){
                // even
                even->next = head;
                even = even->next;
            } else {
                // odd
                odd->next = head;
                odd = odd->next;
            }
            head = head->next;
            c++;
        }
        even->next = nullptr;

        odd->next = even_start->next;

        

        return odd_start->next;
    }
};