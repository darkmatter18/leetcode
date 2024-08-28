class Solution {
    void subsetRe(vector<int>& nums, int idx, vector<int> curr, vector<vector<int>>& res){
        if(idx == nums.size()){
            res.push_back(curr);
            return;
        }
        
        subsetRe(nums, idx+1, curr, res);
        curr.push_back(nums[idx]);
        subsetRe(nums, idx+1, curr, res);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> res;
        
        subsetRe(nums, 0, curr, res);
        
        return res;
    }
};