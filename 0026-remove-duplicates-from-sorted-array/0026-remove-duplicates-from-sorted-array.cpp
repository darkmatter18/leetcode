class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int last_num = -1000;
        vector<int> v;
        for(int num:nums){
            if(last_num != num){
                v.push_back(num);
                last_num = num;
            }
        }
        nums = v;
        return v.size();
    }
};