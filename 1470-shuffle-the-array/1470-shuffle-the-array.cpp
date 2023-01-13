class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n, 0);
        
        int j = 0;
        for(int i = 0; i < n; i++){
            ans[j] = nums[i];
            j++;
            ans[j] = nums[n+i];
            j++;
        }
        return ans;
    }
};