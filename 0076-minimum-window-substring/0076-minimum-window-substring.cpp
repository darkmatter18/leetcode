class Solution {
private:
    unordered_map<char, int> char_s, char_t;
    int checked;
    
    bool isConditionMet(){
        return checked >= char_t.size();
    }
    
    void update_inc(char c){
        if(char_t.find(c) != char_t.end()){
            bool prev = char_s[c] >= char_t[c];    
            char_s[c]++;
            bool now = char_s[c] >= char_t[c];
        
            if(!prev && now)
                checked++;
        }
    }
    
    void update_dec(char c){
        if(char_t.find(c) != char_t.end()){
            bool prev = char_s[c] >= char_t[c];    
            char_s[c]--;
            bool now = char_s[c] >= char_t[c];

            if(prev && !now)
                checked--;
        }
    }
    
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        checked=0;
        
        for(char c: t){
            char_t[c]++;
        }
        
        int si=0, ei=0, len=s.size(), res = INT_MAX, res_si;
        while(ei < len){
            if(isConditionMet()){
                if(res > ei-si){
                    res = ei-si;
                    res_si = si;
                }
                update_dec(s[si]);                
                si++;
            }
            else {
                update_inc(s[ei]);
                ei++;
            }   
        }
        ei--;
        
        while(isConditionMet()){
            if(res > ei-si+1){
                res = ei-si+1;
                res_si = si;
            }
            update_dec(s[si]);
            si++;
        }
        
        if(res == INT_MAX) return "";
        return s.substr(res_si, res);
    }
};