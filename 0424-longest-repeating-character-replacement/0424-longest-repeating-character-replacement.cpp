class Solution {
private:
    bool isValidSubstr(string s, int k, vector<int>& dict){
        int max_char=0;
        for(int i=0; i<26; i++){
            max_char = max(max_char, dict[i]);
        }
        
        return ((int)s.size() - max_char) < k;
    }
public:
    int characterReplacement(string s, int k) {
        int si=0, ei=0, max_len=0;
        vector<int> dict(26, 0);
        
        while(ei < s.size()){
            dict[s[ei] - 'A']++;
            
            while(!isValidSubstr(s.substr(si, ei-si), k, dict)){
                dict[s[si] - 'A']--;
                si++;
            }
            
            max_len = max(max_len, ei-si+1);
            ei++;
        }
        
        return max_len;
    }
};