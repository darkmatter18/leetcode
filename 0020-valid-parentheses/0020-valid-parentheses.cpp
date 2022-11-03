class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        
        bool bad_spotted = false;
        for(char c : s){
            
            if(c == '[' || c == '{' || c == '('){
                cout << "PUSHED " << c << endl; 
                st.push(c);
            } else if( (c == ']' || c == '}' || c == ')') && !st.empty()){
                if(c == ')' && st.top() == '('){
                    st.pop();
                    cout << "POPPED " << c << endl;
                } else if(c == '}' && st.top() == '{'){
                    st.pop();
                    cout << "POPPED " << c << endl;
                } else if(c == ']' && st.top() == '['){
                    st.pop();
                    cout << "POPPED " << c << endl;
                } else{
                    cout << "BAD " << c << endl; 
                    bad_spotted = true;
                    break;
                }
            } else {
                cout << "BAD " << c << endl; 
                bad_spotted = true;
                break;
            }
        }
        
        return !bad_spotted && st.empty();
    }
};