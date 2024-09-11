class Solution {
public:
    int minBitFlips(int start, int goal) {
        int diff = start ^ goal;
        
        // cout << diff;
        
        int count = 0;
        while(diff > 0){
            count += diff & 1;
            diff = diff >> 1;
        }
        
        return count;
    }
};