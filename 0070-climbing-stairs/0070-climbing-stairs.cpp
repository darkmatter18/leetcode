class Solution {
public:
    int climbStairs(int n) {
        long a=1, b=2, s;
        for(int i = 0; i < n-1; i++){
            s = a + b;
            a = b;
            b = s;
        }
        return a;
    }
};