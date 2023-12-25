class Solution {
    int rucursive(string s, int *arr){
        if(s.size() == 0) return 1;
        int ways = 0;
        
        if(arr[s.size()] != -1){
            return arr[s.size()];
        }
        
        if(s[0] != '0'){
            ways += rucursive(s.substr(1), arr);
            if(s.size() >= 2 && s.substr(0, 2) > "0" && s.substr(0, 2) <= "26")
                ways += rucursive(s.substr(2), arr);
        }
        
        arr[s.size()] = ways;
        
        return ways;
    }
    
public:
    int numDecodings(string s) {
        int *arr = new int[s.size()+1];
        for(int i = 0; i < s.size()+1; i++){
            arr[i] = -1;
        }
        
        return rucursive(s, arr);
    }
};