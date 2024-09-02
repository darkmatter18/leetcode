class Solution {
    int minCCS(vector<int>& cost, int idx, vector<int>& dp){
        if(idx >= cost.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        
        dp[idx] = min(minCCS(cost, idx+1, dp), minCCS(cost, idx+2, dp)) + cost[idx];
        return dp[idx];
    }
    
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        
        return min(minCCS(cost, 0, dp), minCCS(cost, 1, dp));
    }
};