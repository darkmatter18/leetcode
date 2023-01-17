class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        int buff = 0;
        for(string s : sentences){
            buff = 0;
            
            if(s.size() == 0)
                continue;
            
            for(char c : s){
                if(c == ' ')
                    buff++;
            }
            buff++;
            
            ans = max(ans, buff);
        }
        
        return ans;
    }
};