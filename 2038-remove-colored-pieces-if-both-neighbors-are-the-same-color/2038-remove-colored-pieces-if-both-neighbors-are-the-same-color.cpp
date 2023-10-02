class Solution {
public:
    bool winnerOfGame(string colors) {
        char last_char = colors[0];
        int last_len = 1;
        
        int a_count = 0;
        int b_count = 0;
        
        for(int i = 1; i < colors.size(); i++){
            if(colors[i] == last_char){
                last_len++;
            }
            else {
                if(last_len - 2 > 0){
                    if(last_char == 'A') a_count += (last_len - 2);
                    else b_count += (last_len - 2);
                }
                last_len = 1;
                last_char = colors[i];
            }
        }
        
        if(last_len - 2 > 0){
            if(last_char == 'A') a_count += (last_len - 2);
            else b_count += (last_len - 2);
        }
        
        if(a_count == 0 && b_count == 0){
            return false;
        }
        
        cout << a_count << " " << b_count;
        return a_count > b_count;
    }
};