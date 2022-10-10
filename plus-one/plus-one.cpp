class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        bool is_carry_end = false;
        for(int i = len-1; i>= 0; i--){
            if(digits[i] == 9){
                // It will produce a carry to have to continue
                is_carry_end = true;
                digits[i] = 0;
            } else{
                digits[i] = digits[i] + 1;
                is_carry_end = false;
                break;
            }
        }
        if(is_carry_end){
            vector<int> v = {1};
            vector<int> ret;
            ret.reserve( v.size() + digits.size() ); // preallocate memory
            ret.insert( ret.end(), v.begin(), v.end() );
            ret.insert( ret.end(), digits.begin(), digits.end() );
            return ret;
        } else{
            return digits;
        }
    }
};