class Solution {
    
    var vis = [Int]()
    
    func dfs( _ node: Int, _ arr: [[Int]]){
        
        
        vis[node] = 1
        
        for index in 0..<arr[node].count{
             if arr[node][index] == 1{
                 if vis[index] == 0{
                     dfs(index, arr)
                 }
             }
        }
    }
    func findCircleNum(_ isConnected: [[Int]]) -> Int {
        vis = Array( repeating: 0, count: isConnected.count)
        
        var ans = 0
        
        for index in 0..<isConnected.count{
            if vis[index] == 0{
                dfs(index, isConnected)
                ans += 1
            }
        }
        
        return ans
        
        
    }
}