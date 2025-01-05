class Solution {
    int recursion(vector<int>& cost, int idx, vector<int>& dp){
        if(idx >= cost.size()){
            return 0;
        }
        
        if(dp[idx] != -1){
            return dp[idx];
        }

        dp[idx] = min(
            recursion(cost, idx+1, dp),
            recursion(cost, idx+2, dp)
        ) + cost[idx];

        return dp[idx];
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);

        int a = recursion(cost, 0, dp);
        int b = recursion(cost, 1, dp);
        return min(a, b);
    }
};