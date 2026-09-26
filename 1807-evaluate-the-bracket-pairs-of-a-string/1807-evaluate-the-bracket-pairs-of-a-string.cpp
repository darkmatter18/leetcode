class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        // Create the map.
        unordered_map<string, string> m;
        for(vector<string> each_knowledge : knowledge){
            m[each_knowledge[0]] = each_knowledge[1];
        }

        int starting_point = -1;
        int ending_point = -1;
        string final_string;
        for(int i = 0; i<s.size(); i++){
            if(starting_point == -1 && s[i] != '('){
                final_string += s[i];
            }

            if(s[i] == '('){
                starting_point = i;

                if(ending_point != -1){
                    // In the middle part
                    final_string += s.substr(ending_point + 1, starting_point-ending_point-1);
                }
            }
            else if(s[i] == ')'){
                ending_point = i;

                // Get the substring from the s
                string key = s.substr(starting_point+1, ending_point-starting_point-1);
                // Get the value from the map.
                if(m.find(key) == m.end()){
                    final_string += '?';
                } else{
                    final_string += m[key];
                }
            }
        }
        
        // Add the ending part
        if(ending_point != -1){
            final_string += s.substr(ending_point + 1);
        }

        return final_string;
    }
};