class Solution {
public:
    string removeDuplicates(string s) {
        int i = 0;
        while (i < s.size()){
            if(s[i] == s[i+1]){
                // deblicate found
                s.erase(i, 2);
                i > 0 ? i-- : i = 0;
                    
                continue;
            }
            i++;
        }
        return s;
    }
};