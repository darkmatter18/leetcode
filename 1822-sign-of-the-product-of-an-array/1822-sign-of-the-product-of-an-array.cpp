class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 1;
        for(int num: nums){
            if(num > 0){
                ans *=1;
            }
            else if (num < 0){
                ans *= -1;
            }
            else {
                return 0;
            }
        }
        return ans;
    }
};