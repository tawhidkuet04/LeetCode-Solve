class Solution {
public:
    
    
    bool canMake(string word, unordered_map<string,int> &mp, unordered_map<string,int> &dp){
        
        if(dp[word]){
            return true;
        }
        
        
        for(int index = 1; index < word.size(); index ++ ){
            string left = word.substr(0, index);
            string right = word.substr(index);
            if(mp[left]){
                if(mp[right] || canMake(right, mp, dp)){
                    dp[word] = 1;
                    return true;
                }
            }
        }
        
        return false;
    }
    
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
       unordered_map<string,int> mp;
       unordered_map<string, int> dp;
       int sz = words.size();
        
       for(int index = 0; index < sz; index ++ ){
           mp[words[index]] = 1;
       }
        
       vector<string> ans;
        
       for(int index = 0; index < sz; index ++ ){
           if(canMake(words[index], mp, dp)){
               ans.push_back(words[index]);
           }
       }
        
        
       return ans; 
        
    }
};