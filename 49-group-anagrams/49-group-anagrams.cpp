class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > mp ;
        
        
        for(int index = 0 ; index < strs.size(); index ++ ){
            string str = strs[index];
            // int charValArr[26] = {0};
            unordered_map<char, int > charValArr;
            
            for(int charIndex = 0 ; charIndex < str.size(); charIndex ++ ){
                  charValArr[ str[charIndex] - 'a' ] ++ ;
            }
            
            string hashedKey = "";
            
            for(int charIndex = 0 ; charIndex < 26 ; charIndex ++ ){
                hashedKey += charValArr[charIndex] + '0';
            }
            
            auto mpStringArray =  mp[hashedKey];
            mpStringArray.push_back(str);
            mp[hashedKey] = mpStringArray;
        }
        vector< vector<string> > ans;
        
        for( auto const keyVal: mp){
            
            ans.push_back(keyVal.second);
        }
        return ans;
    }
};


