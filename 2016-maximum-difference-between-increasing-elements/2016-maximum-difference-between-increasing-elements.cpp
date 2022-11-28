class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size(), ans = INT_MIN;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if (nums[i] > nums[j]){
                    ans = max(ans, nums[i] - nums[j]);
                }
            }
        }
        if(ans == INT_MIN){
            return -1;
        }
        return ans;
    }
};