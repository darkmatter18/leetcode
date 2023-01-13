class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for(string s : operations){
            s[1] == '+' ? x++ : x--;
        }
        return x;
    }
};