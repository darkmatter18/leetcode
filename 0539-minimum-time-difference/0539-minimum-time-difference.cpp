class Solution {
private:
    int strToNum(string time){
        int hr = stoi(time.substr(0, 2));
        int min = stoi(time.substr(3));
                
        return hr*60+min;
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> v;
        
        for(string timePoint : timePoints){
            int num = strToNum(timePoint);
            v.push_back(num);   
        }
        
        // for(int n:v){
        //     cout << n << endl;
        // }
        
        sort(v.begin(), v.end());
        
        int diff = INT_MAX, last_diff;
        for(int i=1; i<v.size(); i++){
            last_diff = abs(v[i]-v[i-1]);
            last_diff = min(last_diff, 1440-last_diff);
            diff = min(diff, last_diff);
        }
        
        last_diff = abs(v[v.size()-1]-v[0]);
        last_diff = min(last_diff, 1440-last_diff);
        diff = min(diff, last_diff);
        
        return diff;
    }
};