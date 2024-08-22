class Solution {
public:
    int findComplement(int num) {
        int length = log2(num)+1;
        
    
        return (((long)1 << length) - 1) ^ num;
    }
};