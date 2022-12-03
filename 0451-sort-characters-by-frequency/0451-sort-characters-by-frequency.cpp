class Solution {
public:
    bool cmp(pair<char, int>& a, pair<char, int>& b){
        return a.second < b.second;
    }

    string frequencySort(string s) {
        map<char, int> ss;
        for(char c: s){
            if(ss.find(c) == ss.end()){
                ss.insert(pair<char, int>(c, 1));
            } else {
                ss[c]++;
            }
        }
        
        // Declare vector of pairs
        vector<pair<char, int>> A;

        // Copy key-value pair from Map
        // to vector of pairs
        for (auto& it : ss) {
            A.push_back(it);
        }

        // Sort using comparator function
        sort(A.begin(), A.end(), [this](pair<char, int>& a, pair<char, int>& b){
            return a.second > b.second;});

        // Print the sorted value
        string ret = "";
        for (auto& it : A) {
            ret.append(string(it.second, it.first));
            // cout << it.first << ' ' << it.second << endl;
        }
        return ret;
        
    }
};