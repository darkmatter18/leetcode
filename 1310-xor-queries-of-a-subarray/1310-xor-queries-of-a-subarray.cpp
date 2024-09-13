class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        for(int i = 1; i < arr.size(); i++){
            arr[i] = arr[i] ^ arr[i-1];
        }
        
        vector<int> res(queries.size());
        for(int i=0; i < queries.size(); i++){
            int left = queries[i][0];
            int right = queries[i][1];
            
            if(left == 0){
                res[i] = arr[right];
                continue;
            }
            
            res[i] = arr[right] ^ arr[left-1];
        }
        
        return res;
    }
};