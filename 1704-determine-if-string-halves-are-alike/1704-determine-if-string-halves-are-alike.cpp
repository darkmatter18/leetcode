class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int c = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' 
               || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                i < n/2 ? c++ : c--;
            }
        }
        
        return c == 0;
    }
};