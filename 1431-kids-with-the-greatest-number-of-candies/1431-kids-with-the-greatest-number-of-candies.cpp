class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_candy = 0;
        for(int n : candies) max_candy = max(max_candy, n);
        
        vector<bool> ret(candies.size());
        
        for(int i = 0; i < candies.size(); i++){
            ret[i] = candies[i] + extraCandies >= max_candy;
        }
        
        return ret;
    }
};