class Solution {
public:

    void dfs( int process, map<int, vector<int>> &mp,  vector<int> & ans){
        
        ans.push_back(process);
    
        for(int index = 0; index < mp[process].size();  index ++ ){
             int nextProcess = mp[process][index];
               dfs(nextProcess,mp, ans);
        }
    }
    
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
       
       vector<int> ans ; 
    
       map<int, vector<int>>mp;
      
       int sz = pid.size();
        
       for(int index = 0; index < sz; index ++ ){
           
           if( ppid[index] != 0 ){
                // auto vect = mp[ppid[index]];
                // vect.push_back(pid[index]);
                mp[ppid[index]].push_back(pid[index]);
           }
       }
        
        dfs(kill, mp, ans);
        
        return ans;
        
    }
};