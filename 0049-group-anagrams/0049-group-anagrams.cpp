class Solution {
public:
    array<int, 26> get_lexo(string str){
        array<int, 26> arr;
        for(int i=0; i<26; i++) arr[i] = 0;
        
        for(char c: str){
            arr[c-'a']++;
        }
        
        return arr;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int, 26>, vector<string>> data;
        
        for(string str: strs){
            array<int, 26> d = get_lexo(str);
            data[d].push_back(str);
        }
        
        vector<vector<string>> ans;
        for(pair<array<int, 26>, vector<string>> p: data){
            ans.push_back(p.second);
        }
        return ans;
    }
};