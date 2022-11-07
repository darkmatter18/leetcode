class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int i = 0, j= 0, perimeter = 0;
        
        for(i = 0; i < grid.size(); i++){
            for(j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    perimeter += 4;
                    
                    // Check Neabours            
                    // 4 points (i-1, j), (i+1, j), (i, j-1), (i, j+1)
                    
                    if(i-1 >= 0 && grid[i-1][j] == 1){
                        // check i-1, j
                        perimeter -= 1;
                    }
                    if(i+1 < grid.size() && grid[i+1][j] == 1){
                        // check i+1, j
                        perimeter -= 1;
                    }
                    if(j-1 >= 0 && grid[i][j-1] == 1){
                        // check i, j-1
                        perimeter -= 1;
                    }
                    if(j+1 < grid[0].size() && grid[i][j+1] == 1){
                        //checl i, j+1
                        perimeter -= 1;
                    }
                }
            }
        }
        return perimeter;
    }
};