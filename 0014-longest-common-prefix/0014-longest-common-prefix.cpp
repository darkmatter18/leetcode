class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int max_len = 202;
        for(string s: strs){
            if(max_len > s.size())
                max_len = s.size(); 
        }
        cout << "Max Len:  " << max_len << endl; 
        
        int min_len = 0;
        
        if(max_len == 0){
            return "";
        }
        
        for(int i = 1; i < strs.size(); i++){
            for(int m = 0; m < max_len; m++){
                // cout << "M Val:  "<< m << strs[i-1][m] << " " << strs[i][m] << endl;
                if(strs[i-1][m] != strs[i][m]){
                    // cout << "T";
                    if(m == 0){
                        cout << "ml u";
                        min_len = -1;
                    }
                    break;
                }
                min_len = m;
            }
            cout << "ML: " << min_len;
            max_len = min_len+1;
            if(min_len == -1)
                break;
        }
        
        return strs[0].substr(0, min_len+1);
    }
};