class Solution {
public:
    int maxScore(string s) {
        int one_count = 0, zero_count=0, total = INT_MIN;
        for(char c:s){
            if(c =='1') one_count++;
        }
        
        
        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] == '0'){
                zero_count++;
            }
            else {
                one_count--;
            }
            total = max(total, (zero_count + one_count));
        }
        return total;
    }
};