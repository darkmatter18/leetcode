class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> s;
        int size = nums.size();
        int res = -1, total = 0;
        
        for(int n : nums){
            if(s.find(n) == s.end()){
                s.insert(n);
                total += n;
            }
            else {
                // n
                res = n;
            }
        }
        return {res, (size * (size+1) / 2) - total };
        
    }
};