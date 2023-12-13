class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> row_sum(mat.size());
        vector<int> col_sum(mat[0].size());
        
        int s;
        for(int i = 0; i < mat.size(); i++){
            s = 0;
            for(int j = 0; j < mat[i].size(); j++){
                s += mat[i][j];
            }
            row_sum[i] = s;
        }
        for(int j = 0; j < mat[0].size(); j++){
            s = 0;
            for(int i = 0; i < mat.size(); i++){
                s += mat[i][j];
            }
            col_sum[j] = s;
        }
        
        int ans = 0;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[i].size(); j++){
                if(mat[i][j] == 1 && row_sum[i]-1 == 0 && col_sum[j]-1 == 0)
                    ans++;
            }
        }
        
        return ans;
    }
};