class Solution {
public:
    int minPartitions(string n) {
        int ans = -1;
        for(char c : n){
            ans = max(ans, (int)(c - '0'));
        }
        return ans;
    }
};