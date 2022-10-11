class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> char_map1;
        map<char, char> char_map2;
        for(int i = 0; i < s.length(); i++){
            // check if s[i] exist in the map or not,
            // if not exist add the pair(s[i], t[i])
            // if exist check if the value of s[i] is matching with t[] or not
            if (char_map1.find(s[i]) == char_map1.end()) {
                char_map1.insert(pair<char, char>(s[i], t[i]));
            } else {
              if(char_map1[s[i]] != t[i]) return false;
            }
            if (char_map2.find(t[i]) == char_map2.end()) {
                char_map2.insert(pair<char, char>(t[i], s[i]));
            } else {
              if(char_map2[t[i]] != s[i]) return false;
            }
        }
        return true;
    }
};