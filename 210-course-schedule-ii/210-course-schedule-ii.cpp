class Solution {
public:
    
    vector<int > graph[2005];
    int vis[2005] = {0};
    int indegree[2005] = {0};
    bool flag = false;
    
    void topSort(int node, vector<int> &ans){
        vis[node] = 1;
        for(int index = 0; index < graph[node].size(); index ++ ){
            int nextNode = graph[node][index];
            
            if(vis[nextNode] == 0){
                topSort(nextNode, ans);
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
        unordered_set<int> st;
        
        for(int index = 0; index < prerequisites.size(); index ++ ){
            int curNode = prerequisites[index][1];
            int nextNode = prerequisites[index][0];
             graph[curNode].push_back(nextNode);
            
             indegree[nextNode] ++;
             st.insert(curNode);
             st.insert(nextNode);
        }
        
        
        for(int course = 0 ; course < numCourses; course ++){
            if(indegree[course] == 0){
                cout << course << endl;
                topSort(course, ans);
            }
        }
        
        reverse(ans.begin(), ans.end());
        if(ans.size() != numCourses) ans.clear();
        
        return ans;
        
    }
};

// 3<---1 <-- 0-- > 2
    