class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> s_m, t_m;
        
        for(char c: s){
            if(s_m.find(c) == s_m.end()){
                s_m.insert(pair<char, int>(c, 1));
            } else {
                s_m[c] += 1;
            }
        }
        for(char c: t){
            if(t_m.find(c) == t_m.end()){
                t_m.insert(pair<char, int>(c, 1));
            } else {
                t_m[c] += 1;
            }
        }
        
        
        // for (auto i: s_m){
        //     cout << i.first << " " << i.second << endl;
        // }
        
        for(char c: t){
            if(s_m.find(c) == s_m.end()){
                return false;
            } else {
                s_m[c] -= 1;
                if(s_m[c] == 0){
                    s_m.erase(c);
                }
            }
        }
        
        for(char c: s){
            if(t_m.find(c) == t_m.end()){
                return false;
            } else {
                t_m[c] -= 1;
                if(t_m[c] == 0){
                    t_m.erase(c);
                }
            }
        }
        return true;
    }
};