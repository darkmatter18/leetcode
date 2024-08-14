class Solution {
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> data;
        
        cS(candidates, target, 0, res, data);
        
        return res;
    }
    
private:
    void cS(vector<int>& candidates, int target, int idx, vector<vector<int>>& res, vector<int> curr){
        if(target < 0 || idx >= candidates.size()) return;
    
        if(target==0){
            res.push_back(curr);
            return;
        }
        
        cS(candidates, target, idx+1, res, curr);
        curr.push_back(candidates[idx]);
        
        cS(candidates, target-candidates[idx], idx, res, curr);
    }
};