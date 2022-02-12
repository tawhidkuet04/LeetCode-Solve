class Solution {
public:

    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        unordered_set<string> wordSet;
        int size = wordList.size();
        
        for(int i = 0; i < size; i ++){
            wordSet.insert(wordList[i]);
        }
        
        queue<string> q;
        unordered_map<string,int> depth;
        q.push(beginWord);
        depth[beginWord] = 1;
        
        while(!q.empty()){
            string word = q.front();
            q.pop();
            if(word == endWord){
               return depth[word];
             } 
             
        
            for(int i = 0; i < word.size(); i ++ ){
                string tempWord = word;
                for(int j = 0; j < 26; j ++){
                   tempWord[i] = j + 'a';
                    if(tempWord == word)continue;
                   
                   if(wordSet.find(tempWord) != wordSet.end()){
                       q.push(tempWord);
                       depth[tempWord] = (depth[word] + 1);
                       wordSet.erase(tempWord);
                   }
                }
            }
        }
        return 0;
        
        
    }
};