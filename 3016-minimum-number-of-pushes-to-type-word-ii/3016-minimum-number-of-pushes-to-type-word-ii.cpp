class Solution {
public:
    int minimumPushes(string word) {
        vector<int> v(26, 0);
        
        for(char c : word){
            v[c-'a']++;
        }
        
        sort(v.begin(), v.end(), std::greater<int>());
        
        int t = 0;
        for(int i=0; i<v.size(); i++){
            t += (v[i] * (i/8 + 1));
        }
        
        return t;
    }
};