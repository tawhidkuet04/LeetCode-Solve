class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums1.size(); i ++ ){
            mp[nums1[i]] = 1;
        }
        vector<int> ans;
        for(int i = 0; i < nums2.size(); i ++ ){
             if(mp[nums2[i]] == 1) {
                 mp[nums2[i]] = 2;
             }
        }
        
        for(auto it: mp){
            if(it.second == 2){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};