class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        
        for(int n: nums){
            if(s.find(n) == s.end()){
                s.insert(n);
            } else{
                return true;
            }
        }
        return false;
    }
};