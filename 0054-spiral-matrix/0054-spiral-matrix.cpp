class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int i=0, dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}, side = 0, x=0, y=0;
        vector<int> res;
        
        
        while(i < m*n){
            res.push_back(matrix[x][y]);
            matrix[x][y] = INT_MIN;
            
            int newX = x + dir[side][0];
            int newY = y + dir[side][1];
            
            if(min(newX, newY) < 0 || newX >= m || newY >= n || matrix[newX][newY] == INT_MIN){
                side = (side+1) % 4;
            }
            
            x += dir[side][0];
            y += dir[side][1];
            i++;
        }
        
        return res;
    }
};