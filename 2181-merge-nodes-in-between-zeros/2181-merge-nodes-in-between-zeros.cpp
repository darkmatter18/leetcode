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
    ListNode* mergeNodes(ListNode* head) {
        int buff = 0;
        
        ListNode *ans;
        ListNode *ret = new ListNode(0);
        
        ans = ret;
        
        while(head != nullptr){
            if(head->val == 0){
                // seek next
                ListNode *n = new ListNode(buff);
                
                // cout << n->val;
                
                ret->next = n;
                ret = ret->next;
                
                buff = 0;
            }
            else{
                // add up
                buff += head->val;
            }
            head = head->next;
        }
        
        return ans->next->next;
    }
    
};