class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nums1Map, nums2Map;
        
        for(int val: nums1){
            nums1Map[val] ++ ;
        }
        
        vector<int> ans;
        
        
        for(int val: nums2){
            nums2Map[val] ++ ;
            
            if(nums1Map[val] > 0){
                nums2Map[val] -- ;
                nums1Map[val] -- ;
                ans.push_back(val);
            }
        }
        
        return ans;
    }
};