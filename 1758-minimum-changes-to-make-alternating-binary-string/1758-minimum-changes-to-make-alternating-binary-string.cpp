class Solution {
public:
    int minOperations(string s) {
        char zero_order_last = '0', one_order_last = '1';
        int zero=0, one=0;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] != zero_order_last) zero++;
            if(s[i] != one_order_last) one++;
            
            zero_order_last = zero_order_last == '0' ? '1' : '0';
            one_order_last = one_order_last == '1' ? '0' : '1';
        }
        
        return min(zero, one);
    }
};