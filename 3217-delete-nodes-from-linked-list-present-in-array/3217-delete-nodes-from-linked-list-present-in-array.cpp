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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> num_set;
        for(int num : nums){
            num_set.insert(num);
        }
        ListNode* h2 = new ListNode(0, head);
        ListNode *h3 = h2;
        
        while(h2 != nullptr){
            ListNode *l = h2->next;
            if(l==nullptr) break;
            if(num_set.contains(l->val)){
                h2->next = l->next;
                delete l;
            }
            else {
                h2 = h2->next;
            }
            
            
        }
        
        return h3->next;
    }
};