class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int b = 0;
        vector<int> n_c(nums);
        vector<int> ans(nums.size());
        
        sort(n_c.begin(), n_c.end());
        
        for(int i = 0; i < nums.size(); i++){
            b = 0;
            while(n_c[b] < nums[i]) b++;
            
            ans[i] = b;
        }
        
        return ans;
    }
};