class Solution {
public:
    string longestPalindrome(string s) {
        int center = 0, l, r, ans = INT_MIN;
        string a;
        while(center < s.size()){
            // Odd palindrome
            l = center, r = center;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                // string will be from center-offset to center+offset
                // if the string is palindrome, increase the offset value and check
                // else break
                // if largest string is captured, use that
                int x = r-l+1;
                if(x > ans){
                    ans = x;
                    a = s.substr(l, x);
                }
                l--, r++;
            }
            
            // Even palindrome
            l = center, r = center+1;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                int x = r-l+1;
                if(x > ans){
                    ans = x;
                    a = s.substr(l, x);
                }
                l--, r++;
            }
            
            center++;
        }
        return a;
    }
};