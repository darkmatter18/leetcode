class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        
        for(int i = 0; i < nums.size(); i++){
            count[nums[i]]++;
        }
        
        vector<int> ret;
        int threshold = nums.size() / 3;
        for(pair<int, int> p: count){
            if(p.second > threshold)
                ret.push_back(p.first);
        }
        
        return ret;
        
    }
};