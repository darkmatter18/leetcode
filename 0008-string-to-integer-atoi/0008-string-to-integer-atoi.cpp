class Solution {
public:
    long myAtoi(string s) {
        bool is_started = false;
        bool is_neg = false;
        long x = 0;
        
        for(char c:s){
            if(!is_started && 
               !(c == ' ' || c == '+' || c == '-' || c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || 
                 c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
              ){
                break;
            }
            else if(!is_started && c == ' '){
                continue;
            }
            else if(is_started && (c == '+' || c == '-'))
                break;
            else if(is_started && c == ' '){
                break;
            }
            else if(is_started &&
               !(c == ' ' || c == '+' || c == '-' || c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || 
                 c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
              ){
                break;
            }
            else if(c == '+' || c == '-'){
                if(c == '-') is_neg = true;
                is_started = true;
            }
            else if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' ||
                    c == '5' || c == '6' || c == '7' || c == '8' || c == '9'){
                is_started = true;
                int i = c - '0';
                // cout << i;
                x = x * 10 + (long)i;
                
                if(!is_neg && (x > INT_MAX))
                    return INT_MAX;
                else if(is_neg && (-x <INT_MIN))
                    return INT_MIN;
                cout << x << endl;
            }
            else if(c == '.'){
                break;
            }
        }
        
        if(is_neg){
            // cout << "N";
            x = -x;
        }
        
        if(x < INT_MIN) x = INT_MIN;
        if(x > INT_MAX) x = INT_MAX;
        
        return x;
    }
};