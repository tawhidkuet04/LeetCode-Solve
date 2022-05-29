class Solution {
public:
    

    
     void solve(int index,string s, vector<string> &ans, string sentence, unordered_map<string, int>& mp, vector<int> & dp){
        // cout << index << endl;
        if(index >= s.size()){
            sentence.pop_back();
            ans.push_back(sentence);
            return;
            // return true;
        }
        
        
        // if(dp[index] != -1) return dp[index];
        // bool flag = false;
        
        
        for(int start = index ; start < s.size(); start ++ ){
              string str = s.substr(index, start - index + 1);
              // cout << str << endl;
              if(mp[str]){
                  // if(sentence.size() == 0){
                  //     sentence += str;
                  // }else{
                  //     sentence += " " + str;
                  // }
                    solve(start + 1, s, ans, sentence + str + " " ,mp, dp);
                  // flag = max(flag, newFlag);
              }
        }
        
         // return  dp[index] = flag;
    }
    
     vector<string> wordBreak(string s, vector<string>& wordDict) {
         unordered_map<string, int> mp;
         vector<int> dp(s.size(), -1);
         vector<string> ans;
         for(auto &str: wordDict){
             mp[str] = 1;
         }
        
         solve(0,s, ans, "", mp, dp);
         return ans;
    }
};