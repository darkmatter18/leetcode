class Solution {
public:
    int rob(vector<int>& nums) {
        int r1 = 0, r2 = 0;
        
        for(int n: nums){
            int t = max(n+r1, r2);
            r1 = r2;
            r2 = t;
        }
        
        return r2;
    }
};