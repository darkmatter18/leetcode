class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(2*nums.size(), 0);
        
        int j = 0;
        for(int x = 0; x < 2; x++){
            for(int i = 0; i<nums.size(); i++){
                ans[j] = nums[i];
                j++;
            }
        }
        return ans;
    }
};