class Solution {
public:
    double average(vector<int>& salary) {
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        
        double ans = 0;
        
        for(int sal : salary){
            maximum = max(maximum, sal);
            minimum = min(minimum, sal);
            
            ans += (double)sal;
        }
        
        ans -= minimum;
        ans -= maximum;
        
        return ans / (salary.size() - 2);
    }
};