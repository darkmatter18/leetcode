class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](vector<int> left, vector<int> right) {
            return sqrt(left[0]*left[0] + left[1]*left[1]) > sqrt(right[0]*right[0] + right[1]*right[1]);           
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> closest(cmp);

        
        for(vector<int> v : points){
            closest.push(v);
        }
        
        vector<vector<int>> res;
        for(int i=0; i<k; i++){
            res.push_back(closest.top());
            closest.pop();
        }
        
        return res;
    }
};