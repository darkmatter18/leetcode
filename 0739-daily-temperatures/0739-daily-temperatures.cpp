// #include<iostream>
// #include<vector>
// #include<climits>

// using namespace std;

class Solution {
public:
    // void print_arr(vector<int>& t){
    //     for(int i: t){
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }

    // void print_d(){
    //     for(int i = 30; i <= 100; i++){
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
    
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int> ans(len, 0);
        vector<int> position(71, -1);
        
        // add the last value's index
        position[temperatures[len-1]-30] = len-1;
        // print_d();
        
        for(int i = len-2; i >= 0; i--){
            // print_arr(position);
            // check if there is a value exist
            int diff = INT_MAX;
            for(int j = temperatures[i]-29; j < 71; j++){
                if(position[j] != -1){
                    // we got a greater value
                    diff = min(diff, position[j] - i);
                    // cout << "T: " << temperatures[i] << " F:" << position[j] << " P:" << i << endl;                    
                }
            }
            if(diff != INT_MAX){
                ans[i] = diff;
            }
            // print_arr(ans);

            if(position[temperatures[i]-30] == -1 || position[temperatures[i]-30] > i){
                position[temperatures[i]-30] = i;
            }
            
        }
        return ans;
    }
};

// int main(int argc, char const *argv[])
// {
//     Solution *s = new Solution();
//     vector<int> v = {73,74,75,71,69,72,76,73};
//     vector<int> a = s->dailyTemperatures(v);
//     s->print_arr(a);
//     return 0;
// }
