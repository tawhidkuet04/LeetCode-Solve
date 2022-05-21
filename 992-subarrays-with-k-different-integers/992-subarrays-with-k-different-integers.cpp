class Solution {
public:
//     4 3 2 1 
//     1 2 3 4
        
//         n - (k - 1)
    int solve( vector<int> & nums, int k){
        int windowStart = 0, sz= nums.size();
        
        unordered_map<int,int> mp;
        
        int ans = 0;
        int windowEnd;
        
        for(windowEnd = 0; windowEnd < sz; windowEnd ++ ){
             mp[nums[windowEnd]] ++;
            
            
             while(windowStart < windowEnd && mp.size() > k){
                      mp[nums[windowStart]] -- ;
                      
                      if(mp[nums[windowStart]] == 0){
                          mp.erase(nums[windowStart]);
                      }
                      
                      windowStart++;
               
                  }
            
              if(mp.size() <= k ){
                  ans += (windowEnd - windowStart + 1 );
              }
        }
        
        
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return solve(nums, k) - solve(nums, k - 1);
        
    }
};


// 4 

// 2
    
    
// 4

    

// 10

// - 3
    
//     10 
    
//     4 + 3 - 
    
//     1 - 4
//     2 - 3 