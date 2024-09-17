class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> data;
        vector<string> res;
        
        size_t pos = s1.find(' ');
        size_t initialPos = 0;
        string temp;

        // Decompose statement
        while( pos != string::npos ) {
            temp = s1.substr( initialPos, pos - initialPos);
            
            data[temp]++;
            
            initialPos = pos + 1;
            pos = s1.find(' ', initialPos);
        }

        // Add the last one
        temp = s1.substr( initialPos, min( pos, s1.size() ) - initialPos + 1 );
        data[temp]++;
        
        pos = s2.find(' ');
        initialPos = 0;

        // Decompose statement
        
        while( pos != string::npos ) {
            temp = s2.substr(initialPos, pos - initialPos);
            data[temp]++;
            
            initialPos = pos + 1;

            pos = s2.find(' ', initialPos );
        }

        // Add the last one
        temp = s2.substr(initialPos, min(pos, s2.size()) - initialPos + 1 );
        data[temp]++;
        
        for(pair<string,int> t: data){
            if(t.second == 1)
                res.push_back(t.first);
        }

        return res;   
    }
};