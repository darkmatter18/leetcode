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
            
            // Get the middle element and check if it is the target
            m = (l+r) / 2;
            if(target == nums[m]){
                return m;
            } 
            
            // middle point is in the left sorted array
            else if(nums[l] <= nums[m]){
                
                // target is greater than middle point, check right
                if(target > nums[m]){
                    l = m+1;
                }
                else {
                    
                    // target is less than middle point and less than left point, check right
                    if(target < nums[l]){
                        l = m+1;
                    }
                    
                    // target is less than middle point and greater than equal to left point, check left
                    else {
                        r = m-1;
                    }
                }
            }
            
            // middle point is in the right sorted array
            else {

                // target is less than middle point, check left array
                if(target < nums[m]){
                    r = m-1;
                }
                
                // target is greater than middle point, it can be in both halves
                else {
                    
                    // target is greater than middle point and greater than the right element, check left
                    if(target > nums[r]){
                        r = m-1;
                    }
                    
                    // target is greater than middle point and less than equal to the right elemtent, check right
                    else {
                        l = m+1;
                    }
                }
            }
        }
        
        return -1;
    }
};