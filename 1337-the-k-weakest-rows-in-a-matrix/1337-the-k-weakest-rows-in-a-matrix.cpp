class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> sol;
        int count = 0, i = 0;
        
        for(vector<int> v: mat){
            count=0;
            for(int i : v){
                if(i==1){
                    count++;            
                }
                else {
                    break;
                }
            }
            sol.push_back(make_pair(i, count));
            i++;
        }
        
        sort(sol.begin(), sol.end(), comp);
        
        vector<int> v;
        for(int i = 0; i < k; i++){
            v.push_back(sol[i].first);
        }
        
        return v;
    }
    
    static bool comp(pair<int, int> i, pair<int, int> j) {
        if(i.second == j.second)
            return i.first < j.first;
        
        return i.second < j.second; 
    }
};