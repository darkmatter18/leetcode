class Solution {
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>> res;
        vector<int> data;
        
        cS(candidates, target, 0, res, data);
        
        vector<vector<int>> output(res.size());
        copy(res.begin(), res.end(), output.begin());
        return output;
    }
    
private:
    void cS(vector<int>& candidates, int target, int idx, set<vector<int>>& res, vector<int> curr){
        if(target < 0 || idx >= candidates.size()) return;
    
        if(target==0){
            res.insert(curr);
            return;
        }
        
        curr.push_back(candidates[idx]);
        
        cS(candidates, target-candidates[idx], idx, res, curr);
        cS(candidates, target-candidates[idx], idx+1, res, curr);
        
        curr.pop_back();
        cS(candidates, target, idx+1, res, curr);
    }
};