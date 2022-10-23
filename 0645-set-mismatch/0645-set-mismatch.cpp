class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        for(int num: nums){
            mp[num] ++ ;
        }
        
        int n = nums.size();
        
        vector<int> ans;
        
        for(int index = 1; index <= n ; index ++ ){
            if(mp[index] > 1){
                ans.push_back(index);
            }
        }
        
        for(int index = 1; index <= n ; index ++ ){
            if(mp[index] ==  0){
                ans.push_back(index);
            }
        }
        
        return ans;
    }
};