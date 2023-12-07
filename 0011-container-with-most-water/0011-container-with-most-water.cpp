class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int area = INT_MIN;
        int curr_area;
        
        while(i < j){
            curr_area = (j-i) * min(height[i], height[j]);
            area = max(area, curr_area);
            
            if(height[i] > height[j]){
                j--;
            }
            else {
                i++;
            }
        }
        
        return area;
    }
};