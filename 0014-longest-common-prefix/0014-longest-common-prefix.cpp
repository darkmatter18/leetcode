class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int max_len = 202, min_len = 0;
        for(string s: strs){
            max_len = min(max_len, (int)s.size());
        }
        
        if(max_len == 0) return "";
        
        for(int i = 1; i < strs.size(); i++){
            for(int m = 0; m < max_len; m++){
                if(strs[i-1][m] != strs[i][m]){
                    if(m == 0){
                        min_len = -1;
                    }
                    break;
                }
                min_len = m;
            }
            max_len = min_len+1;
            if(min_len == -1)
                break;
        }
        
        return strs[0].substr(0, min_len+1);
    }
};