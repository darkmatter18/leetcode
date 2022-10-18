class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> new_nums;
        int len = nums.size();
        for(int n:nums){
            if(n != val){
                new_nums.push_back(n);
            }
        }
        nums = new_nums;
        return new_nums.size();
    }
};