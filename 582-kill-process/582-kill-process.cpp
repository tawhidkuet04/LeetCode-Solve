class Solution {
public:
   
    vector< int > graph [50005];
    void dfs( int process,vector<int> &vis, vector<int> & ans){
        
        ans.push_back(process);
        vis[process] =1;
        for(int index = 0; index < graph[process].size();  index ++ ){
             int nextProcess = graph[process][index];
             if(!vis[nextProcess]){
               
                 dfs(nextProcess,vis, ans);
             }
        }
    }
    
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
       
       vector<int> ans ; 
       
       vector< int > vis(50005, 0);
       int sz = pid.size();
        
       for(int index = 0; index < sz; index ++ ){
           
           if( ppid[index] != 0 ){
                 graph[ppid[index]].push_back(pid[index]);
           }
       }
        
        dfs(kill, vis, ans);
        
        return ans;
        
    }
};