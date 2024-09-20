class Solution {
public:
    string shortestPalindrome(string s) {
        int length = s.length();
        if (length == 0) {
            return s;
        }

        // Find the longest palindromic prefix
        int left = 0;
        for (int right = length - 1; right >= 0; right--) {
            if (s[right] == s[left]) {
                left++;
            }
        }

        // If the whole string is a palindrome, return the original string
        if (left == length) {
            return s;
        }

        // Extract the suffix that is not part of the palindromic prefix
        string nonPalindromeSuffix = s.substr(left);
        string reverseSuffix =
            string(nonPalindromeSuffix.rbegin(), nonPalindromeSuffix.rend());

        // Form the shortest palindrome by prepending the reversed suffix
        return reverseSuffix + shortestPalindrome(s.substr(0, left)) +
               nonPalindromeSuffix;
    }
};

// Left Fix, right moving
// class Solution {
// private:
//     bool isPalindrome(string s, int i, int j){
//         while(i < j){
//             if(s[i] != s[j]){
//                 return false;
//             }
//             i++, j--;
//         }
//         return true;
//     }
    
// public:
//     string shortestPalindrome(string s) {
//         int i=0, j=s.size()-1;
        
//         while(j >= 0){
//             if(isPalindrome(s, i, j)){
//                 break;
//             }
//             j--;
//         }
//         j++;
        
//         string prefix;
//         while(j < s.size()){
//             prefix = s[j] + prefix;
//             j++;
//         }
        
        
//         return prefix + s;
//     }
// };