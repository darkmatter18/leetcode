class Solution {
public:
    int addDigits(int num) {
        if(num < 10) return num;
        
        int sum = 0, r;
        while(num > 0){
            r = num % 10;
            sum += r;
            num /= 10;
        }
        return addDigits(sum);
    }
};