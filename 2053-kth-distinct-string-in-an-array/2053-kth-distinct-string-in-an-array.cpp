class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> m;
        for(string s : arr){
            m[s]++;
        }
        
        int i=0;
        while(k > 0 && i < arr.size()){
            if(m[arr[i]] == 1){
                k--;
                if(k==0){
                    return arr[i];
                }
            }
            i++;
        }
        
        return "";
    }
};