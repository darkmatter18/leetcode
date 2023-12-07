class Solution {
public:
    string largestOddNumber(string num) {
        int i;
        for(i = num.size()-1; i>=0; i--){
            if(int(num[i] - '0') % 2 !=0) break;
        }
        
        // cout << i;
        // if(i==0) return "";
        
        return num.substr(0, i+1);
    }
};