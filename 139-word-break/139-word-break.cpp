class Solution {
public:
    
    bool solve(int index,string s, unordered_map<string, int>& mp, vector<int> & dp){
        // cout << index << endl;
        if(index >= s.size()){
            
            return true;
        }
        
        
        if(dp[index] != -1) return dp[index];
        bool flag = false;
        
        
        for(int start = index ; start < s.size(); start ++ ){
              string str = s.substr(index, start - index + 1);
              // cout << str << endl;
              if(mp[str]){
                  bool newFlag = true & solve(start + 1, s, mp, dp);
                  flag = max(flag, newFlag);
              }
        }
        
         return  dp[index] = flag;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
         unordered_map<string, int> mp;
        vector<int> dp(s.size(), -1);
        
         for(auto &str: wordDict){
             mp[str] = 1;
         }
        
        return solve(0,s, mp, dp);
    }
};
