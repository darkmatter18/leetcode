class Solution {
public:
    string largestGoodInteger(string num) {
        for(string s : {"999", "888", "777", "666", "555", "444", "333", "222", "111", "000"}){
            if(num.find(s) != string::npos){
                return s;
            }
        }
        
        return "";
    }
};