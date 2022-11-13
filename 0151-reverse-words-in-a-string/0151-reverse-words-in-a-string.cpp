class Solution {
public:
    string reverseWords(string s) {
        // Cut and load in a vector
        vector<string> v;
        
        string buff;
        for(char i: s){
            if(i == ' '){
                if(buff.size() > 0){
                    v.push_back(buff);
                }
                buff.clear();
            }
            else {
                buff += i;
            }
        }
        
        if(buff.size() > 0){
            v.push_back(buff);
        }
        
        string res = "";
        for(int i = v.size() - 1; i >= 0; i--){
            res.append(v[i]);
            if(i != 0)
                res += ' ';
        }
        return res;
    }
};