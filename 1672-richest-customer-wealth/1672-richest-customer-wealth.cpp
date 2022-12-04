class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_val = -1;
        for(vector<int> v: accounts){
            int sum = 0;
            for(int bal: v){
                sum += bal;
            }
            if(sum >= max_val){
                max_val = sum;
            }
        }
        return max_val;
    }
};