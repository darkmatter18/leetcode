class Solution {
    long long nC2(int n) {
        // If r is 0 or equal to n, return 1
        if (n == 2) return 1;
        // Initialize the logarithmic sum to 0
        double res = 0;
        // Calculate the logarithmic sum of the numerator and denominator using loop
        for (int i = 0; i < 2; i++) {
            // Add the logarithm of (n-i) and subtract the logarithm of (i+1)
            res += log(n-i) - log(i+1);
        }
        // Convert logarithmic sum back to a normal number
        return (long long)round(exp(res));
    }

    
public:
    int countHomogenous(string s) {
        char c = s[0];
        int curr_len = 1;
        long long total = 0;
        long MOD = 1e9 + 7;
        
        for(int i = 1; i < s.size(); i++){
            if(c == s[i]){
                curr_len++;
            }
            else {
                if(curr_len == 1){
                    // add 1
                    total++;
                    // cout << "Len: " << curr_len << " Total Value: " << total << endl;
                }
                else if (curr_len == 2){
                    total += 3;
                    // cout << "Len: " << curr_len << " Total Value: " << total << endl;
                }
                else {
                    // add this
                    total += (nC2(curr_len) + curr_len);
                    // cout << "Len: " << curr_len <<  " Total Value: " << total << endl;
                }
                c = s[i];
                curr_len=1;
            }
        }
        
        if(curr_len == 1){
            // add 1
            total++;
            // cout << "Len: " << curr_len <<  " Total Value: " << total << endl;
        }
        else if (curr_len == 2){
            total += 3;
            // cout << "Len: " << curr_len << " Total Value: " << total << endl;
        }
        else {
            // add this
            total += (nC2(curr_len) + curr_len);
            // cout << "Len: " << curr_len <<  " Total Value: " << total << endl;
        }
        
        return total % MOD;
    }
};