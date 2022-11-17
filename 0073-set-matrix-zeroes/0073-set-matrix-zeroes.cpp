class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> col, row;
        
        for(int i = 0; i< matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    col.insert(j);
                    row.insert(i);
                }
            }
        }
        
        for(int j: col){
            for(int i = 0; i< matrix.size(); i++){
                matrix[i][j] = 0;
            }
        }
        // cout << endl;
        for(int i: row){
            for(int j = 0; j < matrix[0].size(); j++){
                matrix[i][j] = 0;
            }
        }
    }
};