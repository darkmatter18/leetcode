class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum_of_nums = accumulate(nums.begin(), nums.end(), 0ll);
        long long prefix_sum = 0ll;
        int ways = 0;

        for(int i=0; i<nums.size()-1; i++){
            prefix_sum += nums[i];
            sum_of_nums -= nums[i];

            if(prefix_sum >= sum_of_nums){
                ways++;
            }
        }

        return ways;
    }
};