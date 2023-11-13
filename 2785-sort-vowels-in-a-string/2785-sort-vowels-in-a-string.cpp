class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        
        for(char c: s){
            char l_c = tolower(c);
            if(l_c == 'a' || l_c == 'e' || l_c == 'i' || l_c == 'o' || l_c == 'u'){
                vowels.push_back(c);
            }
        }
        
        sort(vowels.begin(), vowels.end());
        for(char c : vowels){
            cout << c << " ";
        }
        
        for(int i=0, j=0; i < s.size(); i++){
            char l_c = tolower(s[i]);
            if(l_c == 'a' || l_c == 'e' || l_c == 'i' || l_c == 'o' || l_c == 'u'){
                s[i] = vowels[j];
                j++;
            }
        }
        
        return s;
    }
};