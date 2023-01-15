class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int es = 0, ds = 0;
        for(int num : nums){
            es += num;
            ds += getDigitSum(num);
        }
        //cout << es << " " << ds;
        return abs(es-ds);
    }
    
    int getDigitSum(int n){
        int s = 0, m;
        while(n > 0){
            m = n % 10;
            n /= 10;
            s  += m;
        }
        return s;
    }
};