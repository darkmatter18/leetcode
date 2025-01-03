class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s; // set to hold the numbers and get a O(1) while retrival
        int res = 0, tmp;

        // Insert the elements in the set
        for(int num : nums){
            s.insert(num);
        }

        for(int num: nums){
            // Check if the number is the start of the seq
            if(s.find(num-1) != s.end()){
                continue;
            }

            // num is the start of the seq
            tmp = num+1;
            while(s.find(tmp) != s.end()){
                tmp++;
            }
            res = max(res, tmp-num);
        }

        return res;
    }
};