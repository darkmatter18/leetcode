class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int idx_to_put, area, max_area = INT_MIN;
        stack<pair<int, int>> st;
        
        for(int i=0; i<heights.size(); i++){
            idx_to_put = i;
            int curr_el = heights[i];
            
            while(!st.empty() && curr_el < st.top().second){
                pair<int, int> d = st.top();
                st.pop();
                area = (i - d.first) * d.second;
                max_area = max(max_area, area);
                idx_to_put = d.first;
            }
            
            st.push(make_pair(idx_to_put, curr_el));
        }
        
        while(!st.empty()){
            pair<int, int> d = st.top();
            // cout << d.first << " " << d.second << endl;
            st.pop();
            area = (heights.size() - d.first) * d.second;
            max_area = max(max_area, area);
        }
        
        return max_area;
    }
};