class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int i = 0, j, first_zero = nums.size() - 1;
        
        while(i < nums.size()-1){
            //cout << "loop" << i << " " << nums[i] << endl;
            if(nums[i] == nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0;
            }
            i++;
        }
        
        i = 0;
        while(first_zero > -1 && nums[first_zero] != 0){
            first_zero--;
        }
        
        while(first_zero >= 0){
            //cout << "item " << first_zero << " " << nums[first_zero] << endl;
            if(nums[first_zero] == 0){
                // if nums[0] is equal to 0
                // move it until zero comes
                j = first_zero;
                while(j < nums.size() - 1 && nums[j+1] != 0){
                    swap(&nums[j], &nums[j+1]);
                    j++;
                }
            } 
            // else decrese first_zero
            first_zero--;        
        }
        return nums;
    }
    
    void swap(int* a, int* b){
        int t = *a;
        *a = *b;
        *b = t;
    }
};