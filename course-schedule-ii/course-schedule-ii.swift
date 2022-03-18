class Solution {
    var finisTime = [(node: Int, time: Int)]()
    var color = [Int]()
    var isPossible = true
    var time = 0
    
    func dfs(_ node: Int, _ graph: [[Int]]){
        
        time += 1
        
        color[node] = 1
        
        
        for index in 0..<graph[node].count{
            var currentNode = graph[node][index]
            
            if color[currentNode] == 0{
                dfs(currentNode, graph)
            }else if color[currentNode] == 1{
               isPossible = false
               return
            }
        }
        
        
        color[node] = 2
        
        time += 1
        
        finisTime.append( (node: node, time: time ) )
    }
    
    func findOrder(_ numCourses: Int, _ prerequisites: [[Int]]) -> [Int] {
        var graph = Array(repeating: Array(repeating: 0, count:0), count: numCourses)
        color = Array(repeating: 0, count: numCourses )
        
        for arr in prerequisites{
            graph[arr[1]].append(arr[0])
        }
        
        
        for index in 0..<numCourses{
            if color[index] == 0{
                dfs(index, graph)
            }
        }
        
        
        if isPossible{
            finisTime.sort{ $0.1 > $1.1}
            
            var ans = [Int]()

            for node in finisTime{
                ans.append(node.0)
            }
            
            return ans
            
        }else{
            return []
        }
        
        
        
        
    }
}