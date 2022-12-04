class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long s = 0l, ls = 0l; 
        int len = nums.size(), m = INT_MAX, idx, l , r;
        // get the sum
        for(int n: nums) s += n;
        
        for(int i = 0; i < len; i++){
            ls += nums[i];
            s -= nums[i];
            
            l = floor(ls/(i+1));
            
            if ((len-i-1) == 0)
                r = 0;
            else
                r = floor(s/(len-i-1));
            
            // cout << l << " " << r << endl;
            
            int x = abs(l - r);
            if(m > x){
                m = x;
                idx = i;
            }
        }
        
        return idx;
    }
};