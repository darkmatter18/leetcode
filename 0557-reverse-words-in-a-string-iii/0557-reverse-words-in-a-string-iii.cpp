class Solution {
public:
    string reverseWords(string s) {
        int last_word_start = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                reverse(s.begin()+last_word_start, s.begin() + i);
                last_word_start = i + 1;
            }
        }
        
        reverse(s.begin()+last_word_start, s.end());
        
        return s;
    }
};