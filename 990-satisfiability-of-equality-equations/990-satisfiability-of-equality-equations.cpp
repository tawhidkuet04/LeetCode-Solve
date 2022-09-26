class Solution {
public:
    
    vector<int> graph[26];
    int vis[26];
    
    pair<char, char> parseString(string &str){
        return {str[0], str[3]};
    }
    
    bool isEqual(string &str){
        if(str[1] == '=' && str[2] == '='){
            return true;
        }else return false;
    }
    
    
    bool isPresent(int node, int val){
        
        if(node == val) return true;
        vis[node] = 1;
        
        bool flag = false, flagB = false;;
        for(int index = 0; index < graph[node].size(); index ++){
            int nodeB = graph[node][index];
            if(!vis[nodeB]){
                flagB |= isPresent(nodeB, val);
            }
        }
            return flagB;
            
    }
    
   void clearVisArr(){
       for(int index = 0; index < 26; index ++ ){
           vis[index ] = 0;
       }
   }
            
            
    bool equationsPossible(vector<string>& equations) {
              
        vector< pair<char,char> > arr;
    
        for(int index = 0; index < equations.size(); index ++ ){
             auto pairChar = parseString(equations[index]);
            
            if(isEqual(equations[index])){
              
                int nodeA = (int)(pairChar.first - 'a');
                int nodeB = (int)(pairChar.second - 'a');
                
                graph[nodeA].push_back(nodeB);
                graph[nodeB].push_back(nodeA);
                

            }else{
                arr.push_back(pairChar);
            }
        }
        
        for(int index = 0; index < arr.size(); index ++ ){
             auto pairChar = arr[index];
              int nodeA = (int)(pairChar.first - 'a');
                int nodeB = (int)(pairChar.second - 'a');
                
            
            for(int index = 0; index < 26; index ++ ){
                  clearVisArr();
                 if(isPresent(index,nodeA)){
                      clearVisArr();
                     if(isPresent(index,nodeB)){
                         return false;
                     }
                 }
            }
           
        }
        
        return true;
        
    }
};



