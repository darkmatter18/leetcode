class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        for(string tok: tokens){
            if(tok == "+" || tok == "-" || tok == "*" || tok == "/"){
                // pop
                long a = atol(s.top().c_str());
                s.pop();
                long b = atol(s.top().c_str());
                s.pop();
                
                if(tok == "+"){
                    a = a + b;
                } else if(tok == "-"){
                    a =  b - a;
                } else if(tok == "*"){
                    a = a * b;
                } else if(tok == "/"){
                    // cout << a << " " << b << " x";
                    a = b / a;
                    // cout << "a" << a;
                }
                
                s.push(to_string(a));
            } else {
                // push
                s.push(tok);
            }
            // cout << s.top() << endl;
        }
        return atoi(s.top().c_str());
    }
};