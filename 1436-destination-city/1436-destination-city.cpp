class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> s;
        
        for(vector<string> path : paths){
            s.insert(path[0]);    
        }
        
        for(vector<string> path : paths){
            if(s.find(path[1]) == s.end()){
                return path[1];
            }
        }
        return "";
    }
};