class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int old_sum = 0;
        vector<int> new_nums;
        for(int i: nums){
            int s = old_sum + i;
            new_nums.push_back(s);
            old_sum = s;
        }
        return new_nums;
    }
};