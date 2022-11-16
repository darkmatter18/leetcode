class Solution {
public:
    int countSubstrings(string s) {
        int c = 0;
        
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                if(is_palindrome(s, i, j)){
                    c++;
                }
            }
        }
        return c;
    }
    
    bool is_palindrome(string str, int s, int e){
        if(s == e){
            return true;
        }
        for(int i = s, j = e; i < j; i++, j--){
            if(str[i] != str[j]){
                return false;
            }
        }
        return true;
    }
};