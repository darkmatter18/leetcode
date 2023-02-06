class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        
        for(int i = 0; i < nums.size(); i+=2){
            vector <int> t(nums[i], nums[i+1]);
            // res += t;
            res.insert(res.end(), t.begin(), t.end());

        }
        
        
        return res;
    }
};