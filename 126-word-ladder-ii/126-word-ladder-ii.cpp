class Solution {
public:
    unordered_map<string, int > mp;
   unordered_map<string, int > lev;
    
    unordered_map<string , vector<string> > par;
    
    void bfs(string beginWord, string endWord){
        queue<string> q;
        
        q.push(beginWord);
        
        lev[beginWord] = 1;
        int level = 1;
        while(!q.empty()){
            int qSize = q.size();
            
            for(int index = 0; index < q.size(); index ++ ){
                auto front = q.front();
                q.pop();
                
                for(int charIndex = 0; charIndex < front.size(); charIndex ++ ){
                   bool comeToEnd = false;
                    for(char ch = 'a'; ch <= 'z'; ch ++ ){
                            string newString = front;
                            newString[charIndex] = ch;
                            
                            if(mp[newString] && ch != front[charIndex] ){
                                
                                if(lev[newString] == 0){
                                    q.push(newString);
                                    par[newString].push_back(front);
                                    lev[newString] = lev[front] + 1;        
                                }else if (lev[newString] == lev[front] + 1){
                                     par[newString].push_back(front);
                                }
                               
                                
                                if(newString == endWord){
                                    comeToEnd = true;
                                    break;
                                }
                            }
                        }
                    
                    if(comeToEnd)break;
                }
                 level ++ ;
                // for(auto visStr : vis){
                //     mp[visStr.first] --;
                // }
            }
           
        }
         
    }
    
    void generatePath(string word, string beginWord, vector<string> path, vector< vector<string> > &ans){
        if(word == beginWord){
            path.push_back(beginWord);
            reverse(path.begin(), path.end());
            ans.push_back(path);
            return ;
        }
        path.push_back(word);
        
        for( auto parWord: par[word]){
            generatePath(parWord, beginWord, path, ans);
            // path.pop_back();
        }
    }
    
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        for(auto &word: wordList){
            mp[word] ++ ;
        }
        
        
        bfs(beginWord, endWord);
        
        vector<string> path;
        vector< vector<string> > ans;
        
        generatePath(endWord, beginWord, path, ans);
        
        return ans;
        
    }
};


