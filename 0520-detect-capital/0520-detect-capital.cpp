class Solution {
public:
    bool detectCapitalUse(string word) {
        bool all_caps = true;
        for(char c : word){
            if(!(c >= 65 && c <= 90)){
                // one is small
                all_caps = false;
                break;
            }
        }
        
        if(all_caps) return true;
        
        for(int i = 1; i < word.size(); i++){
            if(word[i] >= 65 && word[i] <= 90){
                // one is cap
                return false;
            }
        }
        return true;
    }
};