class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        int buff;
        
        for(vector<int> query : queries){
            buff = 0;
            // cout << query[0] << endl;
            for(vector<int> point : points){
                if(sqrt(pow(abs(query[0] - point[0]), 2) + pow(abs(query[1] - point[1]), 2)) <= query[2]){
                    buff++;
                }
            }
            ans.push_back(buff);
        }
        
        return ans;
    }
};