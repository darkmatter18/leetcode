class Solution {
private:
    void permute(vector<int>& nums, vector<int> curr, vector<vector<int>> &resp){
        if(nums.empty()){
            resp.push_back(curr);
            return;
        }
        
        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            
            vector<int> c(nums.begin(), nums.end());
            c.erase(c.begin()+i);
            
            curr.push_back(num);
            permute(c, curr, resp);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> resp;
        vector<int> curr;
        
        permute(nums, curr, resp);
        
        return resp;
    }
};