class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int s = 0;
        
        // Push elements in the pq
        for(int i : piles){
            pq.push(i);
        }
        
        // Devidng by 2
        for(int i = 0; i < k; i++){
            int x = pq.top();
            pq.pop();
            // cout << x << endl;
            pq.push((x - x/2));
        }
        
        // Adding the elements
        while(!pq.empty()){
            s += pq.top();
            pq.pop();
        }
        
        return s;
    }
};