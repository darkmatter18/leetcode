class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1, m;
        
        while(l <= r){
            // cout << l << " " << r << endl;
            if(nums[l] < nums[r]){
                // do normal binary search
                while(l <= r){
                    m = (l+r) / 2;
                    if(target == nums[m]){
                        return m;
                    }
                    else if(target > nums[m]){
                        // check big
                        l = m+1;
                    }
                    else {
                        r = m-1;
                    }
                }
                break;
            }
            
            m = (l+r) / 2;
            if(target == nums[m]){
                return m;
            } 
            else if(nums[l] <= nums[m]){
                // mid is in the left part
                if(target > nums[m]){
                    l = m+1;
                }
                else {
                    if(target < nums[l]){
                        l = m+1;
                    }
                    else {
                        r = m-1;
                    }
                }
            }
            else {
                // mid is in the right part
                if(target < nums[m]){
                    r = m-1;
                }
                else {
                    if(target > nums[r]){
                        r = m-1;
                    }
                    else {
                        l = m+1;
                    }
                }
            }
        }
        
        return -1;
    }
};