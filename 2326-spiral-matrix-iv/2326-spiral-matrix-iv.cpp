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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        int currDir = 0, i=0, j=0;
        
        int nav[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        
        while(head != nullptr){
            res[i][j] = head->val;
            
            int newI = i + nav[currDir][0], newJ = j + nav[currDir][1];
            
            if(min(newI, newJ) < 0 || newI >= m || newJ >= n || res[newI][newJ] != -1){
                currDir = (currDir + 1) % 4;
            }
            i += nav[currDir][0];
            j += nav[currDir][1];
            
            head = head->next;
        }
        
        return res;
    }
};