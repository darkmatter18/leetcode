class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        set<char> s;
        for(char c: jewels) s.insert(c);
        
        for(char st : stones){
            if(s.find(st) != s.end())
                count++;
        }
        
        return count;
    }
};