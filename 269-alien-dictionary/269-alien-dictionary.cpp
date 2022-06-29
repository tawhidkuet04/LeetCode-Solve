class Solution {
public:
    
    vector<char> graph[26];
    
    int vis[26] = {0};
    int indegree[26] = {0};
    
    
    void topSort(int node, string &ans, string &val){
        
        vis[node] = 1;
        
        for(int index = 0; index < graph[node].size(); index ++ ){
             int nextNode = graph[node][index];
            
             if(vis[nextNode] == 0){
                 topSort(nextNode, ans, val);
             }else if(vis[nextNode] == 1){
                 val = "-1";
                 return;
             }
        }
        // cout << ans << endl;
        ans += (node + 'a');
        vis[node] = 2;
        
    }
    string alienOrder(vector<string>& words) {
         
          
         vector<char> startPoints;
         unordered_set<char> st;
        
        for(auto word: words){
            for(auto ch: word){
                st.insert(ch);
            }
        }
        
         for(int index = 0; index < words.size() - 1; index ++ ){
            string current = words[index];
            string next = words[index + 1];
             
             int mn = min(current.size(), next.size());
             
             if(current.size() > next.size() && current.substr(0,mn) == 
               next.substr(0, mn)){
                 return "";
             }
            for(int i = 0; i < min(current.size(), next.size());  i ++ ){
                if( current[i] != next[i]){
                    graph[current[i] - 'a'].push_back(next[i]  - 'a');   
                    break;
                }
            }
            
         }
        
        
         string ans = "", val = "";
        
        for( auto node: st){
            if(!vis[node-'a']){
                 topSort(node - 'a', ans, val);
            }
            
        }
        
       
    
        
        reverse(ans.begin(), ans.end());
       
        if(val == "-1"){
            ans = "";
        }
        
        return ans;
    }
};

    // w -- r
    // r -- t, f
    // e - r, t
    // f - t
//     w e r f t 
    
    
//     w  e
//     | /
//     r
//     | \
//     t --f