class Solution {
public:
    
    vector<int> graph[505];
    int vis[505];
    unordered_set<int> st[100005];
    
    bool isSameBus(int node, int nextNode){
        for( auto bus: st[node]){
            if(st[nextNode].find(bus) != st[nextNode].end()){
                return true;
            }
        }
        return false;
    }
    
    int bfs(int source, int target){
        if(source == target) return 0;
        if(isSameBus(source, target)){
            return 1;
        }
        
        int dis[100005] = {100000};
        
        unordered_set<int> des;
        
        int newSource;
        
        
        queue<int> q;
       
        
        for(auto bus: st[source]){
             q.push(bus);
             vis[bus] = 1;
             dis[bus] = 1;
        }
        
        for(auto bus: st[target]){
            des.insert(bus);
        }
       
        int minStep = 1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            if(des.find(node) != des.end()){
                return dis[node];
            }
            
            for(int index = 0; index < graph[node].size(); index ++ ){
                  int nextNode = graph[node][index];
                
        
                  if( !vis[nextNode]){
                      q.push(nextNode);
                      dis[nextNode] = dis[node] + 1;
                      vis[nextNode] = 1;
                  }
            }
          
                minStep ++;
            
            
        }
        
        return -1;
    }
    
    
    bool intersect(vector<int> &a, vector<int> &b){
        int i = 0,  j = 0;
        
        while( i < a.size() && j < b.size()){
            if(a[i] == b[j]) return true;
            else if( a[i] < b[j]){
                i ++ ;
            }else{
                j ++ ;
            }
        }
        return false;
    }
    
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        for(int index = 0; index < routes.size(); index ++ ){
            sort(routes[index].begin(), routes[index].end());
            for(int route = 0; route < routes[index].size(); route ++ ){
                 int node = routes[index][route];
                 st[node].insert(index);             
            }
        }
        
        
        for(int i = 0; i < routes.size(); i ++ ){
            for(int j = i + 1; j < routes.size(); j ++ ){
                if(intersect(routes[i], routes[j])){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        return bfs(source, target);
    }
};


// 1 -- 1
// 2 -- 1
// 7 -- 1,2
// 3 -- 2
// 6 -- 2

// 1 2 7 