class Solution {
public:
    
    int bfs(string beginWord, string endWord, vector<string>& wordList, unordered_map<string,int> &mp){
        queue<string> q;
        q.push(beginWord);
        
        int step = 1 ;
        mp[beginWord] = 0;
        while(!q.empty()){
           
            int qSize = q.size();
            for(int qIndex = 0; qIndex< qSize; qIndex ++ ){
                
                 string str = q.front();
                 q.pop();
                 int strSize = str.size();
                
                for(int index = 0; index < strSize; index ++){
                for(char ch = 'a'; ch <= 'z'; ch ++ ){
                    string transformedChar = str;
                    transformedChar[index] = ch;
                    
                    if(mp[transformedChar]){
                        cout << transformedChar << endl;
                        mp[transformedChar] = 0;
                        if(transformedChar == endWord){
                            return step + 1;
                        }
                        q.push(transformedChar);
                    }
                }
            }
            }
            
            
            step ++ ;
            
        }
        return 0;
        
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> mp;
        
        int sz = wordList.size();
        
        for(int index = 0; index < sz; index ++ ){
            mp[wordList[index]] = 1;
        }
        
        return bfs(beginWord, endWord, wordList, mp );
        
    }
};