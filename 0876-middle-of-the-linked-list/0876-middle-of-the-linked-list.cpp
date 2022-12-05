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
    ListNode* middleNode(ListNode* head) {
        ListNode* node_new = head;
        int len = 0;
        while(node_new != nullptr){
            len++;
            node_new = node_new->next;
        }
        int mid = (len / 2);
        while(mid--){
            head = head->next;
        }
        return head;
        
        
//         if(len % 2 == 0){
//             // even
//             int mid = (len / 2) + 1;
//         } else {
//             // odd
//             int mid = (len / 2) + 1;
            
//         }
    }
};