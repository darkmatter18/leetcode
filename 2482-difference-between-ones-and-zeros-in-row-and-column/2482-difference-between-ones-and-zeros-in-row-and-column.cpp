class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int> onesRow(grid.size());
        vector<int> onesCol(grid[0].size());
        vector<int> zerosRow(grid.size());
        vector<int> zerosCol(grid[0].size());
        
        int sum = 0;
        for(int i = 0; i < grid.size(); i++){
            sum = 0;
            for(int j = 0; j < grid[0].size(); j++){
                sum += grid[i][j];
            }
            onesRow[i] = sum;
            zerosRow[i] = grid[0].size() - sum;
        }
        
        for(int j = 0; j < grid[0].size(); j++){
            sum = 0;
            for(int i = 0; i < grid.size(); i++){
                sum += grid[i][j];
            }
            onesCol[j] = sum;
            zerosCol[j] = grid.size() - sum;
        }
        
        
        vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size()));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                ans[i][j]=onesRow[i]+onesCol[j]-zerosRow[i]-zerosCol[j];
            }
        }
        
        return ans;
    }
};