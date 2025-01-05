class Solution {
public:
    void recursive(vector<int>& candidates, int idx, int target, vector<vector<int>>& res, vector<int> inter){
        if(target == 0){
            res.push_back(inter);
            return;
        }
        if(target < 0 || idx >= candidates.size()){
            return;
        }

        inter.push_back(candidates[idx]);
        recursive(candidates, idx, target-candidates[idx], res, inter);
        inter.pop_back();
        recursive(candidates, idx+1, target, res, inter);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> inter;

        recursive(candidates, 0, target, res, inter);

        return res;
    }
};