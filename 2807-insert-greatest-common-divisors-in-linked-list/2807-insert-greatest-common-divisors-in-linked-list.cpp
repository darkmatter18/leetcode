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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* h2 = head;
        
        while(h2 != nullptr && h2->next != nullptr){
            int g = gcd(h2->val, h2->next->val);
            ListNode *n = new ListNode(g, h2->next);
            h2->next = n;
            
            h2 = h2->next->next;
        }
        
        return head;
    }
};