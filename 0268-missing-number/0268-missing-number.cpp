class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long total = n * (n+1) / 2;
        for(int i: nums){
            total -= i;
        }
        return total;
    }
};