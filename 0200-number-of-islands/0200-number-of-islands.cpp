class Solution {
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited){
        if(min(i, j) < 0 || i >= grid.size() || j >= grid[0].size() || visited[i][j] || grid[i][j] != '1')
            return;
        
        visited[i][j] = true;
        
        int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for(int k =0; k<4; k++){
            dfs(grid, i+dir[k][0], j+dir[k][1], visited);
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        
        int count = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    dfs(grid, i, j, visited);
                    count++;
                }
            }
        }
        
        return count;
    }
};