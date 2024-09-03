class Solution {
private:
    int sumOfDigits(int num){
        int res = 0;
        while(num > 0){
            res += num % 10;
            num /= 10;
        }
        return res;
    }

public:
    int getLucky(string s, int k) {
        int num = 0;
        for(char c : s){
            num += sumOfDigits(c- 'a' + 1);
        }
        
        for(int i=1; i<k; i++){
            num = sumOfDigits(num);
        }
        return num;
    }
};