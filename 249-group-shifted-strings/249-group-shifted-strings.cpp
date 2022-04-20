class Solution {
public:
    
    char shiftLetter(char letter, char shift){
        return (letter - shift + 26)  % 26+ 'a';
    }
    
    
    string getHash(string s){
        string hashKey = "";
        for(char character: s){
            hashKey += shiftLetter(character, s[0]);
        }
        return hashKey;
    }
        
    vector<vector<string>> groupStrings(vector<string>& strings) {
        
      map<string , vector<string> > mpHashToList;
      vector< vector<string> > ans;
        
      for( string str: strings){
          string hashKey = getHash(str);
          mpHashToList[hashKey].push_back(str);
      }
      
        for(auto it: mpHashToList){
            ans.push_back(it.second);
        }
        
        return ans;
        
    }
};
