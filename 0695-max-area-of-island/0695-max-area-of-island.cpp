class Solution {
    void dfs(vector<vector<int>>& grid, int i, int j, int &count, vector<vector<bool>>& visited){
        if(min(i, j) < 0 || i >= grid.size() || j >= grid[0].size() || visited[i][j] || grid[i][j] != 1)
            return;
        
        visited[i][j] = true;
        count++;
        
        int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for(int k =0; k<4; k++){
            dfs(grid, i+dir[k][0], j+dir[k][1], count, visited);
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        
        int maxCount = 0, count = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(!visited[i][j] && grid[i][j]){
                    count = 0;
                    dfs(grid, i, j, count, visited);
                    maxCount = max(maxCount, count);
                }
            }
        }
        
        return maxCount;
    }
};