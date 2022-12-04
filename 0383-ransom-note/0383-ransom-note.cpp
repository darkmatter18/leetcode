class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> m;
        for(char c: magazine){
            if(m.find(c) == m.end()){
                m.insert(pair<char, int>(c, 1));
            } else {
                m[c]++;
            }
        }
        
        for(char c: ransomNote){
            if(m.find(c) == m.end()){
                return false;
            } else {
                m[c]--;
                if(m[c] <= 0)
                    m.erase(c);
            }
        }
        
        return true;
    }
};