class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int y_diff = abs(fy - sy);
        int x_diff = abs(fx - sx);
        // cout << "Y: " << y_diff;
        // cout << " X: " << x_diff;
        
        if (x_diff == 0 && y_diff == 0 && t == 1) {
            return false;
        }
        
        return t >= max(y_diff, x_diff);
        
    }
};