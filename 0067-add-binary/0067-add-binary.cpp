class Solution {
public:
    string addBinary(string a, string b) {
        int a_l = a.size(), b_l = b.size();
        int max_len = a_l > b_l ? a_l : b_l;
        
        a = string(max_len - a_l, '0').append(a);
        b = string(max_len - b_l, '0').append(b);
        
        // cout << a << endl;
        // cout << b << endl;
        
        int carry = 0;
        string s;
        for(int i = max_len - 1; i >= 0; i--){
            int ans =  int(a[i] - '0') + int(b[i] - '0') + carry;
            if(ans == 2){
                // carry
                carry = 1;
                ans = 0;
            } else if(ans == 3){
                carry = 1;
                ans = 1;
            } else {
                // not carry
                carry = 0;
            }
            
            s = to_string(ans) + s;
        }
        
        if(carry > 0){
            s = "1" + s;
        }
        
        return s;
    }
};