// class Solution {
// private:
//     int strToNum(string time){
//         int hr = stoi(time.substr(0, 2));
//         int min = stoi(time.substr(3));
                
//         return hr*60+min;
//     }
// public:
//     int findMinDifference(vector<string>& timePoints) {
//         vector<int> v;
        
//         for(string timePoint : timePoints){
//             int num = strToNum(timePoint);
//             v.push_back(num);   
//         }
        
//         // for(int n:v){
//         //     cout << n << endl;
//         // }
        
//         sort(v.begin(), v.end());
        
//         int diff = INT_MAX, last_diff;
//         for(int i=1; i<v.size(); i++){
//             last_diff = abs(v[i]-v[i-1]);
//             last_diff = min(last_diff, 1440-last_diff);
//             diff = min(diff, last_diff);
//         }
        
//         last_diff = abs(v[v.size()-1]-v[0]);
//         last_diff = min(last_diff, 1440-last_diff);
//         diff = min(diff, last_diff);
        
//         return diff;
//     }
// };

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // create buckets array for the times converted to minutes
        vector<bool> minutes(24 * 60, false);
        for (string time : timePoints) {
            int h = stoi(time.substr(0, 2));
            int m = stoi(time.substr(3));
            int min = h * 60 + m;
            if (minutes[min]) return 0;
            minutes[min] = true;
        }
        int prevIndex = INT_MAX;
        int firstIndex = INT_MAX;
        int lastIndex = INT_MAX;
        int ans = INT_MAX;

        // find differences between adjacent elements in sorted array
        for (int i = 0; i < 24 * 60; i++) {
            if (minutes[i]) {
                if (prevIndex != INT_MAX) {
                    ans = min(ans, i - prevIndex);
                }
                prevIndex = i;
                if (firstIndex == INT_MAX) {
                    firstIndex = i;
                }
                lastIndex = i;
            }
        }

        return min(ans, 24 * 60 - lastIndex + firstIndex);
    }
};