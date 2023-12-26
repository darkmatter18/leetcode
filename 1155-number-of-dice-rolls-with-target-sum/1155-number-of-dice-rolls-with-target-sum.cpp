class Solution {
    long helper(int n, int k, int target, map<pair<int, int>, long> &m){
        long MOD = 1e9+7;
        if(n == 0 && target == 0) return 1;
        if(n <= 0 || target <= 0) return 0;
        
        pair<int, int> p(n, target);
        
        if(m.find(p) != m.end()) return m[p];
        
        long total = 0;
        for(int i = 1; i <= k; i++){
            total += helper(n-1, k, target-i, m);
        }
        
        long ans = total % MOD;
        m[p] = ans;
        // cout << n << " " << k << " " << target << " " << ans << endl;
        return total % MOD;
        
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        map<pair<int, int>, long> m;
        return (int) helper(n, k, target, m);
    }
};