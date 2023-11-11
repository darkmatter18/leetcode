class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ret(pref.size());
        if(pref.size() == 0) return ret;
        
        ret[0] = pref[0];
        for(int i = 1; i < pref.size(); i++){
            ret[i] = pref[i] ^ pref[i-1];
        }
        
        return ret;
    }
};