class Solution {
    bool isPrefixAndSuffix(string s1, string s2){
        if(s1.size() > s2.size()){
            return false;
        }

        for(int i=0; i<s1.size(); i++){
            if(s1[i] != s2[i]) {
                return false;
            }
        }

        int x = s2.size()-1;
        for(int i=s1.size()-1; i>=0; i--,x--){
            if(s1[i] != s2[x]) {
                return false;
            }
        }

        return true;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;

        for (int i = 0; i<words.size(); i++){
            for(int j=i+1; j<words.size(); j++){
                if(isPrefixAndSuffix(words[i], words[j])){
                    count++;
                }
            }
        }

        return count;
    }
};