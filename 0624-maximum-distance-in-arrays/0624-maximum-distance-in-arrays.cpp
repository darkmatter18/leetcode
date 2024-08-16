class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        pair<int, int> the_max = make_pair(INT_MIN, -1);
        pair<int, int> second_max = make_pair(INT_MIN, -1);
        pair<int, int> the_min = make_pair(INT_MAX, -1);
        pair<int, int> second_min = make_pair(INT_MAX, -1);
        
        for(int i=0; i<arrays.size(); i++){
            int curr_max = arrays[i][arrays[i].size()-1];
            int curr_min = arrays[i][0];
            
            
            if(the_max.first == INT_MIN){
                the_max = make_pair(curr_max, i);
            }
            else if (curr_max >= the_max.first){
                second_max = the_max;
                the_max = make_pair(curr_max, i);
            } 
            else if(the_max.first > curr_max && second_max.first < curr_max){
                second_max = make_pair(curr_max, i);
            }
            
            if(the_min.first == INT_MAX){
                the_min = make_pair(curr_min, i);
            }
            else if (curr_min <= the_min.first){
                second_min = the_min;
                the_min = make_pair(curr_min, i);
            } 
            else if(the_min.first < curr_min && second_min.first > curr_min){
                second_min = make_pair(curr_min, i);
            }
        }
        
        // cout << the_max.first << " " << the_max.second << " " << second_max.first << " " << second_max.second << endl;
        // cout << the_min.first << " " << the_min.second << " " << second_min.first << " " << second_min.second << endl;
        
        if(the_max.second != the_min.second){
            return the_max.first - the_min.first;
        }
        else {
            return max(the_max.first-second_min.first,  second_max.first-the_min.first);
        }
        
        return 2;
    }
};