class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int m_total = accumulate(rolls.begin(), rolls.end(), 0);
        
        int total = mean * (m+n);
        int n_total = total-m_total;
        
        float n_each = (float)n_total / (float)n;
        vector<int> rolls_m;
        
        if(n_each < 1 || n_each > 6){
            return rolls_m;
        }
        
        rolls_m.resize(n, n_total/n);
        int reminder = n_total%n;
        
        int i=0;
        while(reminder > 0){
            int old_val = rolls_m[i];
            rolls_m[i] = min(6, reminder+rolls_m[i]);
            
            reminder -= (rolls_m[i] - old_val);
            i++;
        }
        
        return rolls_m;
    }
};