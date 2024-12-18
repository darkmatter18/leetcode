// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // Answer vector. Returning the value including the discount
        vector<int> ans(prices.size());
        
        // Loop though the input vector
        for(int i=0; i<prices.size(); i++){
            
            // Taking the dicscout variable to get if any discount is applicable or not
            int dis = INT_MAX;
            
            // Looping from the next element to the end to get the discounted value, if any.
            for(int j=i+1; j<prices.size(); j++){
                if(prices[j] <= prices[i]){
                    dis = prices[j];
                    break;
                }
            }
            
            // If dis is INT MAX, that means no discount value is found.
            if(dis != INT_MAX){
                ans[i] = prices[i] - dis;
            }
            else {
                ans[i] = prices[i];
            }
        }
        
        return ans;
    }
};