class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0;
        int curr_sum = 0, min_len = INT_MAX;
        while(i < nums.size()){
            if(curr_sum >= target){
                min_len = min(min_len, (j-i));
                curr_sum -= nums[i];
                i++;
            } else if(j < nums.size()) {
                curr_sum += nums[j];
                j++;
            } else {
                break;
            }
        }
        if(min_len == INT_MAX)
            return 0;
        return min_len;
    }
};