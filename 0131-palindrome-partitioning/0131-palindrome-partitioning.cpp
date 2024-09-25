class Solution {
private:
    bool isPalindrome(string s){
        for(int i=0, j=s.size()-1; i < j; i++, j--){
            if(s[i] != s[j]) return false;
        }
        return true;
    }
    
    void backtrack(string s, vector<string> curr, vector<vector<string>> &res){
        if(s.size() == 0) {
            if(curr.size() > 0){
                res.push_back(curr);
            }
            return;
        }
        
        for(int i=1; i <= s.size(); i++){
            // i is the curr size
            if(isPalindrome(s.substr(0, i))){
                curr.push_back(s.substr(0, i));
                backtrack(s.substr(i), curr, res);
                curr.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        vector<vector<string>> res;
        
        backtrack(s, curr, res);
        
        return res;
    }
};