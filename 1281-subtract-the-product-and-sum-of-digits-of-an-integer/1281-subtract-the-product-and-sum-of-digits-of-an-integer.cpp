class Solution {
public:
    int subtractProductAndSum(int n) {
        int s = 0, prod = 1, r;
        while(n > 0){
            r = n % 10;
            s += r;
            prod *= r;
            n /= 10;
        }
        
        return prod - s;
    }
};