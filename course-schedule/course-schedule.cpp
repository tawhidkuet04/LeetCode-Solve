class Solution {
public:
    
    bool dfs(int node, vector< vector< int> > &graph, vector< int > &vis, bool &ans){
        
        
        vis[node] = 1;
        bool flag = true;
        for(int index = 0; index < graph[node].size(); index ++ ){
            int nextNode = graph[node][index];
            if(vis[nextNode] == 0){
               
                if(dfs(nextNode, graph, vis, ans)) return true;
                
            }else if(vis[nextNode] == 1){
                return true;
            }
        }
        vis[node] = 2;

        return false;
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector< vector< int> > graph(numCourses, vector<int>(0,0));
        
        vector<int> vis(numCourses, 0);
        
        
        for(int index = 0; index < prerequisites.size(); index ++ ){
            int first = prerequisites[index][0];
            int second = prerequisites[index][1];
            graph[second].push_back(first);

        }
        
        bool ans = true;

        for(int index = 0; index < numCourses; index ++){
            if(vis[index] == 0){
                bool flag = dfs(index, graph, vis, ans);
                if(flag){
                    return false;
                }
            }
        }
        return true;
        
//         [[1,4],[2,4],[3,1],[3,2]]
        
//         1<---3
//         1<---4
//         2<---4
        
    }
};