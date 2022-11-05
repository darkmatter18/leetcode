class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binary_search(nums, 0, nums.size() - 1, target);
    }
    int binary_search(vector<int>& nums, int f, int l, int target){
        if (f > l){
            return -1;
        }
        int mid = (f+l)/2;
        if(nums[mid] == target){
            return mid;
        } else if(nums[mid] > target){
            // check the lower part
            return binary_search(nums, f, mid - 1, target);
        } else {
            // check the upper part
            return binary_search(nums, mid + 1, l, target);
        }
    }
};