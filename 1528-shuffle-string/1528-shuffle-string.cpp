class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string out(s.size(), '*');
        for(int i = 0; i < indices.size(); i++){
            out[indices[i]] = s[i];
        }
        return out;
    }
};