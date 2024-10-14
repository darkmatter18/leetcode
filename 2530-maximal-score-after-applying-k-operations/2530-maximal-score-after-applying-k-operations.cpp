class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        
        for(int num : nums){
            pq.push(num);
        }
        
        long long total = 0;
        for(int i=0; i<k; i++){
            int t = pq.top();
            pq.pop();
            
            total += t;
            if(t % 3 == 0){
                pq.push(t/3);
            }
            else {
                pq.push(t/3+1);
            }
        }
        
        return total;
    }
};