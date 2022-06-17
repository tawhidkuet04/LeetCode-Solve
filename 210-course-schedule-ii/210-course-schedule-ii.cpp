class Solution {
public:
    
    
   
    bool flag = false;
    
    void topSort(int node, vector<int> &ans,  vector< vector<int> > &graph, vector<int> &vis){
        vis[node] = 1;
        for(int index = 0; index < graph[node].size(); index ++ ){
            int nextNode = graph[node][index];
            
            if(vis[nextNode] == 0){
                topSort(nextNode, ans, graph, vis);
            }else if(vis[nextNode] == 1){
                flag = true;
                return ;
            }
        }
        vis[node] = 2;
        ans.push_back(node);
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        
       vector< vector<int> > graph(numCourses);
        vector<int> vis(numCourses,0), indegree(numCourses,0);

        
        for(int index = 0; index < prerequisites.size(); index ++ ){
            int curNode = prerequisites[index][1];
            int nextNode = prerequisites[index][0];
             graph[curNode].push_back(nextNode);
            
             indegree[nextNode] ++;
        }
        
        
        for(int course = 0 ; course < numCourses; course ++){
            if(indegree[course] == 0){
                topSort(course, ans, graph, vis);
            }
        }
        
        reverse(ans.begin(), ans.end());
        if(ans.size() != numCourses) ans.clear();
        
        return ans;
        
    }
};

// 3<---1 <-- 0-- > 2
    