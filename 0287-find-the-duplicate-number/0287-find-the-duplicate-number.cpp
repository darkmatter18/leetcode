class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> ss;
        for(int n: nums){
            if(ss.find(n) == ss.end()){
                // insert
                ss.insert(n);
            } else {
                // return
                return n;
            }
        }
        return -1;
    }
};