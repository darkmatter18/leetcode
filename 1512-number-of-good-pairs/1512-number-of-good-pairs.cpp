class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int total = 0;
        vector<int> count(101, 0);
        
        for(int n : nums){
            count[n-1]++;
        }
        
        for(int c : count)
            total += (c * (c-1) / 2);
        
        return total;
    }
};