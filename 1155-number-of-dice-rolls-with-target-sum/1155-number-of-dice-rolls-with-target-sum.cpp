class Solution {
    long helper(int n, int k, int target, long **data){
        long MOD = 1e9+7;
        if(n == 0 && target == 0) return 1;
        if(n <= 0 || target <= 0) return 0;
        
        if(data[n][target] != -1) return data[n][target];
        
        long total = 0;
        for(int i = 1; i <= k; i++){
            total += helper(n-1, k, target-i, data);
        }
        
        long ans = total % MOD;
        data[n][target] = ans;
        return total % MOD;
        
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        // map<pair<int, int>, long> m;
        
        long **data = new long*[n+1];
        for(int i = 0; i < n+1; i++){
            data[i] = new long[target+1];
            for(int j = 0;j < target+1; j++){
                data[i][j] = -1;
            }
        }
        
        return (int) helper(n, k, target, data);
    }
};