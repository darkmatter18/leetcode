class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Row Validation
        for(vector<char> v: board){
            if(!rowValidate(v))
                return false;
        }
        
        cout << "COL VAL";
        
        for(int i = 0; i < board[0].size(); i++){
            if(!colValidate(board, i))
                return false;
        }
        
        cout << "ROW VAL" << endl;
        
        set<char> s;
        for(int x = 0; x < 3; x++){
            for(int y = 0; y < 3; y++){
                // this is a single block
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        cout << i << " " << x << " "<< i+x*3 << " " << j+y*3 << endl;
                        char c = board[i+x*3][j+y*3];
                        if(c != '.'){
                            if(s.find(c) == s.end()){
                                s.insert(c);
                            }
                            else {
                                return false;
                            }
                        }
                    }
                }
                s.clear();
            }
        }
        
        
        return true;
    }
    
    bool rowValidate(vector<char> &v){
        set<char> s;
        for(char c: v){
            if(c != '.'){
                if(s.find(c) == s.end()){
                    s.insert(c);
                }
                else {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool colValidate(vector<vector<char>> &b, int j){
        set<char> s;
        for(int i = 0; i < b.size(); i++){
            if(b[i][j] != '.'){
                
                if(s.find(b[i][j]) == s.end()){
                    s.insert(b[i][j]);
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};