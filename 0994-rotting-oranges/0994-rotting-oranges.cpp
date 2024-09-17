class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh_count = 0, time = 0;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 2){
                    q.push(make_pair(i, j));
                }
                else if(grid[i][j] == 1){
                    fresh_count++;
                }
            }
        }
        
        // cout << "Init " <<  fresh_count << endl;
        
        while(!q.empty()){
            vector<pair<int, int>> v;
            // cout << "At time " << time;
                
            // Get the rotten oranges
            while(!q.empty()){
                v.push_back(q.front());
                q.pop();
            }
            
            // cout << " Vector: " << v.size();
            for(pair<int, int> p : v){
                
                int row[4] = {-1, 0, 1, 0};
                int col[4] = {0, -1, 0, 1};
                
                // For each adj nodes
                for(int i=0; i<4; i++){
                    
                    int x = p.first + row[i];
                    int y = p.second + col[i];
                    
                    // Not out of bound and having a fresh orange
                    if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1){
                        grid[x][y] = 2;
                        q.push(make_pair(x, y));
                        fresh_count--;
                        // cout << " (" << x << ", " << y << "), ";
                    }
                }
            }
            // cout << endl;
            time++;
        }
        
        if(fresh_count == 0){
            if(time == 0) return 0;
            return time-1;
        }
        return -1;
    }
};