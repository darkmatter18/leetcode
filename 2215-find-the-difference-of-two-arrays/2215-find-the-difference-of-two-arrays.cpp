class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans1;
        vector<int> ans2;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i=0, j=0;
        
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                if(ans1.empty() || ans1[ans1.size()-1] != nums1[i])
                    ans1.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i] > nums2[j]) {
                if(ans2.empty() || ans2[ans2.size()-1] != nums2[j])
                    ans2.push_back(nums2[j]);
                j++;
            }
            else {
                // equal
                int t = nums1[i];
                while(i < nums1.size() && nums1[i] == t){
                    i++;
                }
                while(j < nums2.size() && nums2[j] == t){
                    j++;
                }
            }
        }
        
        while(i < nums1.size()){
            ans1.push_back(nums1[i]);
            int t = nums1[i];
            while(i < nums1.size() && nums1[i] == t){
                i++;
            }
        }
        while(j < nums2.size()){
            ans2.push_back(nums2[j]);
            int t = nums2[j];
            while(j < nums2.size() && nums2[j] == t){
                j++;
            }
        }
        
        vector<vector<int>> ans{ans1, ans2};
        return ans;
    }
};