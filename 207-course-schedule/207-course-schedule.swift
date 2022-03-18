class Solution {
    
    var graph = [[Int]]()
    var vis = [Int]()
    var ans = true
    
    func dfs(_ node: Int){

        vis[node] = 1
        print(node)
        for index in 0..<graph[node].count{
            if vis[graph[node][index]] == 0{
                 dfs(graph[node][index])
            }else if vis[graph[node][index]] == 1{
                ans = false
                return
            }
               

        }
        
        vis[node] = 2
        
        
    }
    
    func canFinish(_ numCourses: Int, _ prerequisites: [[Int]]) -> Bool {
        graph = Array(repeating: Array(repeating: 0 , count: 0) , count: numCourses)
        vis = Array(repeating: 0, count: numCourses)
        
       for arr in prerequisites{
           graph[arr[1]].append(arr[0])
       }
        
        print(graph)
        for index in 0..<numCourses{
            if vis[index] == 0 {
                dfs(index)
            }
        }
        
        return ans
    }
}