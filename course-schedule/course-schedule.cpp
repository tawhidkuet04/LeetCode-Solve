class Solution {
public:
    
    void dfs(int node, vector< vector< int> > &graph, vector< int > &vis, bool &ans){
        
        
        vis[node] = 1;
        cout << graph[node].size() << endl;
        for(int index = 0; index < graph[node].size(); index ++ ){
            int nextNode = graph[node][index];
            if(vis[nextNode] == 0){
                 dfs(nextNode, graph, vis, ans);
            }else if(vis[nextNode] == 1){
                ans = false;
                // return false;
            }
        }
        vis[node] = 2;

        // return true;
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector< vector< int> > graph(numCourses, vector<int>(0,0));
        
        vector<int> vis(numCourses, 0);
        
        
        for(int index = 0; index < prerequisites.size(); index ++ ){
            int first = prerequisites[index][0];
            int second = prerequisites[index][1];
            // cout << first << " " << second << endl;
            
            graph[second].push_back(first);

        }
        
        bool ans = true;

        for(int index = 0; index < numCourses; index ++){
            if(vis[index] == 0){
                 dfs(index, graph, vis, ans);
                // cout << index << " "<< flag << endl;
                // if(!flag){
                //     return false;
                // }
            }
        }
        return ans;
        
//         [[1,4],[2,4],[3,1],[3,2]]
        
//         1<---3
//         1<---4
//         2<---4
        
    }
};