class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1, m;
        
        int min_val = INT_MAX;
        while(l <= r){
            m = (l+r) / 2;
            if(nums[l] < nums[r]){
                min_val = min(min_val, nums[l]);
                break;
            }
            // cout << l << " " << r << " " << m << endl;

            min_val = min(min_val, nums[m]);
            
            if(nums[m] >= nums[l]){
                // mid is in the left sorted array
                // search the right part
                l = m+1;
            }
            else {
                // mid is in the left sorted array
                // search the left part
                r = m-1;
            }
        }
        
        return min_val;
    }
};