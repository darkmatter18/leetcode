class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int col = strs[0].size();
        int a = 0, last = 96;
        
        for(int i = 0; i < col; i++){
            last = 96;
            for(string s: strs){
                if(last == 96){
                    last = (int)s[i];
                    continue;
                }
                if(last <= (int)s[i]){
                    last = (int)s[i];
                }
                else {
                    // cout << i << endl;
                    a++;
                    break;
                }
            }
        }
        return a;
    }
};