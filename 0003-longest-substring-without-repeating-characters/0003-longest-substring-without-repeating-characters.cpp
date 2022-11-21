class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, ans = INT_MIN, curr_len = 0;
        set<char> chars;
        
        while(i < s.size()){
            if(chars.find(s[i]) == chars.end()){
                chars.insert(s[i]);
                curr_len++;
                i++;
                
                ans = max(ans, curr_len);
            }
            else {
                chars.erase(s[j]);
                curr_len--;
                j++;
            }
        }
        if(ans == INT_MIN)
            return 0;
        return ans;
    }
};