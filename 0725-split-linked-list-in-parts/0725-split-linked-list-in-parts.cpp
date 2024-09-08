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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k);
        ListNode* h2 = head;
        
        int len = 0;
        while(h2 != nullptr){
            len++;
            h2 = h2->next;
        }
        
        int eachPart = (len / k);
        
        // Increase the length of the firstNInc by 1
        int firstNInc = len % k;
        
        int counter = 0;
        int idx = 0;
        
        while(head != nullptr){
            if(counter == 0){
                res[idx] = head;
            }
            counter++;
            
            if((firstNInc > 0 && counter == eachPart+1) || (firstNInc == 0  && counter == eachPart)){
                // cout << firstNInc << "CO" << counter << endl;
                // Update the current last node endpoint to nullptr
                h2 = head;
                head = head->next;
                h2->next = nullptr;
                
                counter = 0;
                idx++;
                
                if(firstNInc > 0) firstNInc--;
            }
            else {
                head = head->next;
                
            }
        }
        
        return res;
    }
};