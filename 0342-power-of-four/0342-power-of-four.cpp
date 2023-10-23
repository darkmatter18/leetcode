class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        float ans = log_a_to_base_b((float)n, 4.0);
        // cout << ans;
        return (float)(ans - int(ans)) == 0.0;
    }
    
    float log_a_to_base_b(float a, float b){
        return log2(a) / log2(b);
    }
};