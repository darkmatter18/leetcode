class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        
        long long ans = skill[0] * skill[skill.size()-1];
        int initialSum = skill[0] + skill[skill.size()-1];
        
        int i = 1, j = skill.size()-2;
        
        while(i < j){
            if(skill[i] + skill[j] != initialSum){
                return -1;
            }
            ans += (skill[i] * skill[j]);
            i++, j--;
        }
        
        return ans;
    }
};