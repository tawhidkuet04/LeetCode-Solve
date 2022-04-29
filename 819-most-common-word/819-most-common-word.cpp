class Solution {
public:

    
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> mp;
        unordered_set<string> bannerSet(banned.begin(), banned.end());
        
        string word = "";
        for( char &c: paragraph){
            c = (!isalpha(c)) ? ' ': tolower(c); 
        }
        for( char &character: paragraph){
             if(!isalpha(character)){
                 if(word.size() > 0){
                     mp[word] ++ ;
                 }
                 word = "";
             }else{
                 word += character;
             } 
        }
        
         if(word.size() > 0){

             mp[word] ++ ;
         }
        
        int maxLength = 0;
        string freqWord = "";
        
        for(auto &wordPair: mp){
            string word = wordPair.first;
            int freq = wordPair.second;
            
            if(bannerSet.find(word) == bannerSet.end()){
                if(freq > maxLength){
                    maxLength = freq;
                    freqWord = word;
                }
            }
        }
        return freqWord;
    }
};