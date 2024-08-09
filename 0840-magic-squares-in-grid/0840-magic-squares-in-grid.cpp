class Solution {
    bool isMagicSquare(vector<vector<int>>& grid, int x, int y){
        set<int> ss;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(grid[x+i][y+j] > 9 || grid[x+i][y+j] < 1) return false;
                ss.insert(grid[x+i][y+j]);
            }
        }
        // cout << "A";
        if(ss.size() != 9) return false;
        
        int row_sum, s = INT_MIN;
        for(int i=0; i<3; i++){
            row_sum = 0;
            for(int j=0; j<3; j++){
                row_sum += grid[x+i][y+j];
            }
            if(s==INT_MIN){
                s = row_sum;
            }
            else if(s != row_sum){
                return false;
            }
        }
        // cout << "B";
        
        for(int i=0; i<3; i++){
            row_sum = 0;
            for(int j=0; j<3; j++){
                row_sum += grid[x+j][y+i];
            }
            if(s != row_sum){
                return false;
            }
        }
        // cout << "C";
        
        row_sum = 0;
        for(int i=0; i<3; i++){
            row_sum += grid[x+i][y+i];
        }
        if(s != row_sum){
            return false;
        }
        // cout << "D";
        
        row_sum=0;
        for(int i=0; i<3; i++){
            row_sum += grid[x+i][y+2-i];
        }
        if(s != row_sum){
            return false;
        }
        // cout << "E";
        return true;
    }
    
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if(grid.size() < 3 || grid[0].size() < 3)
            return 0;
        
        int max_row = grid.size() - 2;
        int max_col = grid[0].size() - 2;
        
        int count = 0;
        for(int i=0; i<max_row; i++){
            for(int j=0; j<max_col; j++){
                if(isMagicSquare(grid, i, j)){
                    count++;
                }
            }
        }
        
        return count;
    }
};