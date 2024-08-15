class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int collection[3] = {0, 0, 0};
        
        for(int bill : bills){
            if(bill == 5){
                collection[0]++;
            }
            else if(bill == 10){
                if(collection[0] == 0){
                    return false;
                }
                collection[0]--;
                collection[1]++;
            }
            else {
                // 1-10, 1-5 or 3-5 
                if(collection[1] >= 1 && collection[0] >= 1){
                    collection[0]--;
                    collection[1]--;
                    collection[2]++;
                }
                else if (collection[0] >= 3){
                    collection[0] -= 3;
                    collection[2]++;
                }
                else {
                    return false;
                }
            }
        }
        
        return true;
    }
};