class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, ls=0;
        for(int i: nums){
            sum += i;
        }
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]+ls == sum-ls){
                return i;
            }
            ls+= nums[i];
            
        }
        return -1;
    }
};