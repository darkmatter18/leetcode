class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        
        for(int i = 1; i <= numRows; i++){
            vector<int> v(i, 1);
            if(i == 1 || i == 2){
                ret.push_back(v);
                continue;
            }
            // cout << i << endl;
            for(int j = 1; j < i-1; j++){
                // If i = 3 j is (1)
                
                v[j] = ret[i-2][j-1] + ret[i-2][j];
            }
            ret.push_back(v);
        }
        return ret;
    }
};