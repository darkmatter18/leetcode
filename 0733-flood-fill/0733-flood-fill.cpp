class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        fill(image, sr, sc, color, image[sr][sc]);
        return image;
    }
    void fill(vector<vector<int>>& image, int sr, int sc, int color, int old_val){
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()){
            cout << "Overflow" << endl;
            return;   
        }
            
        if(image[sr][sc] != old_val || image[sr][sc] == color)
            return;
        
        image[sr][sc] = color;
        
        fill(image, sr, sc+1, color, old_val);
        fill(image, sr, sc-1, color, old_val);
        fill(image, sr+1, sc, color, old_val);
        fill(image, sr-1, sc, color, old_val);
    }
};