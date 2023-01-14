class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        for(char a: address){
            if(a == '.'){
                ans += '[';
                ans += '.';
                ans += ']';
            }
            else{
                ans += a;
            }
        }
        return ans;
    }
};