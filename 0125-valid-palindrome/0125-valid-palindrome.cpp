class Solution {
public:
    bool isPalindrome(string s) {
        int f = 0, l = s.size() - 1;
        while(f < l){
            while(!isalnum(s[f]) && f < l)
                f++;
            while(!isalnum(s[l]) && f < l)
                l--;
            
            // cout << s[f] << " " <<  s[l] << endl;
            
            if(tolower(s[f]) != tolower(s[l])){
                return false;
            }
            f++;
            l--;
        }
        return true;
    }
};