class Solution {
private:
    string data[9] = {
        "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(string digits, string curr, vector<string> &res){
        if(digits.empty()){
            if(!curr.empty())
                res.push_back(curr);
            return;
        }
        
        for(char c : data[digits[0]-'1']){
            
            backtrack(digits.substr(1), curr+c, res);            
        }
    }
    
    
public:
    vector<string> letterCombinations(string digits) {
        string curr;
        vector<string> res;
        
        backtrack(digits, curr, res);
        return res;
    }
};