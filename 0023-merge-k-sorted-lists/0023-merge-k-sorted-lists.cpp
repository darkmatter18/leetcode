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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *headans = nullptr, *tailans = nullptr;
        int i, min_data, min_idx = -1;

        while(1){
            // search through the lists and get the min index in i;
            for(i = 0, min_data = INT_MAX, min_idx = -1; i < lists.size(); i++){
                ListNode *head_curr = lists[i];
                if(head_curr != nullptr && head_curr->val < min_data){
                    min_data = head_curr->val;
                    min_idx = i;
                }
            }
            
            
            if(min_idx == -1){
                // everything is null, break
                break;
            }
            
            if(headans == nullptr){
                headans = lists[min_idx];
                tailans = headans;
            }
            else{
                tailans->next = lists[min_idx];
                tailans = tailans->next;
            }
            
            lists[min_idx] = lists[min_idx]->next;
            
            // if(lists[min_idx] != nullptr)
            //     cout << min_idx << " " << lists[min_idx]->val << endl;
            // else
            //     cout << min_idx << endl;
                
        }
        
        return headans;
        
    }
};