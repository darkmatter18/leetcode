class Solution {
private:
    bool isConsistent(string word, bool exists[]){
        for(char c : word){
            if(!exists[c-'a']) return false;
        }
        
        return true;
    }

public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool exists[26];
        for(int i=0; i<26; i++){
            exists[i] = false;
        }
        for(char c: allowed){
            exists[c-'a'] = true;
        }
        
        int res = 0;
        for(string word : words){
            if(isConsistent(word, exists)){
                res++;
            }
        }
        
        return res;
    }
};