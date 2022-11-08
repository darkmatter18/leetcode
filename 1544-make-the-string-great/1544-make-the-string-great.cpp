class Solution {
public:
    string makeGood(string s) {
        int i=0;
        while(i < s.size()-1){
            cout << "SIZE: " << s.size() << " ";
            cout << s << endl;
            if(checkBadness(s[i], s[i+1])){
                cout << "BAD at " << i << endl;
                s.erase(i, 2);
                i = 0;
            } else{
                cout << "At else" << endl;
                i++;
            }
            if(s.size() == 0){
                break;
            }
        }
        return s;
    }
    
    bool checkBadness(char a, char b){
        
        if((islower(a) && !islower(b)) || (islower(b) && !islower(a))){
            if(tolower(a) == tolower(b)){
                return true;
            }
        }
        
        return false;;
    }
};