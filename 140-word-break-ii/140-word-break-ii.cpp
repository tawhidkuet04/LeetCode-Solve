class Solution {
public:
    

    
     void solve(int index,string s, vector<string> &ans, string sentence, unordered_map<string, int>& mp){
        if(index >= s.size()){
            sentence.pop_back();
            ans.push_back(sentence);
            return;
        }
        
        for(int start = index ; start < s.size(); start ++ ){
              string str = s.substr(index, start - index + 1);
              if(mp[str]){
                    string newStr = sentence + str + " ";
                    solve(start + 1, s, ans, newStr , mp);
              }
        }

    }
    
     vector<string> wordBreak(string s, vector<string>& wordDict) {
         unordered_map<string, int> mp;
         
         vector<string> ans;
         
         for(auto &str: wordDict){
             mp[str] = 1;
         }
        
         solve(0,s, ans, "", mp);
         return ans;
    }
};