class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return get_idx(nums, target, 0, nums.size());
    }
    int get_idx(vector<int>& nums, int target, int start, int end){
        int mid = (end + start)/ 2;
        cout << start << " " << end << " " << mid << endl;
        if(start == end){
            return end;
        }
        
        if(nums[mid] == target){
            return mid;
        } else if(nums[mid] < target){
            // Check the great once
            return get_idx(nums, target, mid + 1, end);
            
        } else {
            // check the less once
            return get_idx(nums, target, 0, mid);
        }
    }
};