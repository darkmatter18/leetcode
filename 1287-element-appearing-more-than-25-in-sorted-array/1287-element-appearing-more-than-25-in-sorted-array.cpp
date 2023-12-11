class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> count;
        for(int num:arr){
            if(count.find(num) == count.end()){
                count[num] = 1;
            }
            else {
                count[num]++;
            }
        }
        
        
        for(auto data: count){
            if(data.second > arr.size()/4){
                return data.first;
            }
        }
        return -1;
    }
};