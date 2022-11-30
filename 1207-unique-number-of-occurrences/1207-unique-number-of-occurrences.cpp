class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> occr;
        set<int> oc;
        
        for(int i: arr){
            if(occr.find(i) == occr.end()){
                occr.insert(pair<int, int>(i, 1));
            } else {
                occr[i]++;
            }
        }
        
        for(auto x: occr){
            cout << x.first << " " << x.second << endl;
            if(oc.find(x.second) == oc.end()){
                oc.insert(x.second);
            }
            else {
                return false;
            }
        }
        
        return true;
        
    }
};