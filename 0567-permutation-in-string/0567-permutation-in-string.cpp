class Solution {
private:
    bool check(vector<int> s1, vector<int> s2){        
        for(int i=0; i<26; i++){
            if(s1[i] != s2[i]){
                return false;
            }
        }
        
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1_map(26, 0), s2_map(26, 0);
        
        if(s1.size() > s2.size()) return false;
        
        for(char c: s1){
            s1_map[c - 'a']++;
        }
        
        int i=0, j=0;
        while(i < s1.size()){
            s2_map[s2[i] - 'a']++;
            i++;
        }
        
        for(i=0, j=s1.size(); j<s2.size(); i++, j++){
            if(check(s1_map, s2_map)){
                return true;
            }
            s2_map[s2[j] - 'a']++;
            s2_map[s2[i] - 'a']--;
        }
        if(check(s1_map, s2_map)){
            return true;
        }
        
        return false;
        
    }
};