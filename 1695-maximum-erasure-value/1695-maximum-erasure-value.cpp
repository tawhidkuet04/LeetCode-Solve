class Solution {
public:
    
    void createCumalativeArray(vector<int> &cum, vector<int> &nums){
        for(int index = 0; index < nums.size(); index ++ ){
            cum[index + 1] = cum[ index ] + nums[index];
        }
            
    }
    
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int sz = nums.size();
        
        vector<int> cum( sz + 1, 0);
        
        createCumalativeArray(cum, nums);
        
        int windowStart = 0;
        
        unordered_map<int,int> mp;
        
        int ans = 0;
        
        for(int windowEnd = 0; windowEnd < sz; windowEnd ++ ){
              mp[nums[windowEnd]] ++ ;
            
               while(mp[nums[windowEnd]] > 1){
                    mp[nums[windowStart]] -- ;
                    windowStart ++;
               }
            
            ans = max(ans, cum[windowEnd + 1] - cum[windowStart]);
            
        }
        
        return ans;
        
    }
};