class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> ss;
        for(int n: nums){
            if(ss.find(n) == ss.end()){
                // insert
                ss.insert(n);
            } else{
                // remove the existing
                ss.erase(n);
            }
        }
        vector<int> v(ss.begin(), ss.end());
        return v[0];
    }
};