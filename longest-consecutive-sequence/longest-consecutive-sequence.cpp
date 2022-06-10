class Solution {
public:
    
    int solve(int num, vector<int> &nums, unordered_map<int,int> &mp){
        
        if(mp[num] == 0) return 0;
        
        if(mp[num] != 1) return mp[num];
        
        return mp[num] = 1 + solve( num + 1, nums, mp);
    }
    
    int longestConsecutive(vector<int>& nums) {
          unordered_map<int,int> mp;
        
          int sz = nums.size();
        
          for(int index = 0; index < sz; index++ ){
              mp[nums[index]] = 1;
          }
        
        int ans = 0;
        
        for(int index = 0; index < sz; index ++ ){
            ans = max(ans, solve(nums[index], nums, mp));
        }
        
        return ans;
    }
};