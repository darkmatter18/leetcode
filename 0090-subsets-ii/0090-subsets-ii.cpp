class Solution {
    void subsetRe(vector<int>& nums, int idx, vector<int> curr, set<vector<int>>& res){
        if(idx == nums.size()){
            sort(curr.begin(), curr.end());
            res.insert(curr);
            return;
        }
        
        subsetRe(nums, idx+1, curr, res);
        curr.push_back(nums[idx]);
        subsetRe(nums, idx+1, curr, res);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        set<vector<int>> res;
        
        subsetRe(nums, 0, curr, res);
        
        vector<vector<int>> output(res.size());
        copy(res.begin(), res.end(), output.begin());
        
        return output;
    }
};