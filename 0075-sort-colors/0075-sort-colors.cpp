class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> m;
        for(int num: nums){
            if(m.find(num) == m.end()){
                m.insert(pair<int, int>(num, 1));
            } else {
                m[num]++;
            }
        }
        int idx = 0;
        for(int i = 0; i<m[0]; i++){
            nums[idx] = 0;
            idx++;
        }
        for(int i = 0; i<m[1]; i++){
            nums[idx] = 1;
            idx++;
        }
        for(int i = 0; i<m[2]; i++){
            nums[idx] = 2;
            idx++;
        }
        
    }
};