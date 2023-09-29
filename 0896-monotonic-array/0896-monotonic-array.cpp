class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() == 1 || nums.size() == 2) return true;
        
        bool decided = false;
        bool is_increasing;
        
        for(int i = 1; i < nums.size(); i++){
            if(decided){
                if(is_increasing){
                    if(nums[i] < nums[i-1]) return false;
                } 
                else {
                    if(nums[i] > nums[i-1]) return false;
                }
            }
            else {
                if(nums[i] > nums[i-1]){
                    decided = true;
                    is_increasing = true;
                }
                else if (nums[i] < nums[i-1]){
                    decided = true;
                    is_increasing = false;
                }
            }
        }
        
        return true;
    }
};