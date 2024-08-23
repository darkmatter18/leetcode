class Solution {
private:
    int get_gcd(int a, int b){
        if(a == 0) return b;
        return gcd(b % a, a);
    }

public:
    string fractionAddition(string expression) {
        int totalNum = 0;
        int totalDenum = 1;
        
        int i=0, currNum, currDenum;
        bool isNeg = false;
        
        while(i<expression.size()){
            currNum=0, currDenum=0;
            isNeg = false;
            
            if(expression[i] == '-' || expression[i] == '+'){
                if(expression[i] == '-')
                    isNeg = true;
                i++;
            }
            while(isdigit(expression[i])){
                currNum = currNum*10 + expression[i] - '0';
                i++;
            }
            i++;
            while(i<expression.size() && isdigit(expression[i])){
                currDenum = currDenum*10 + expression[i] - '0';
                i++;
            }
            
            
            if(isNeg){
                currNum *= -1;
            }
            totalNum = totalNum * currDenum + currNum*totalDenum;
            totalDenum = totalDenum * currDenum;
            
        }
        
        int gcd = abs(get_gcd(totalNum, totalDenum));
        
        totalNum /= gcd;
        totalDenum /= gcd;
                
        return to_string(totalNum) + "/" + to_string(totalDenum);
    }
};