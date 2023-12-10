class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int size_x = matrix.size();
        int size_y = matrix[0].size();
        vector<vector<int>> data(size_y, vector<int>(size_x));
        
        for(int i = 0; i < size_y; i++){
            for(int j = 0; j < size_x; j++){
                data[i][j] = matrix[j][i];
            }
        }
        
        return data;
    }
};