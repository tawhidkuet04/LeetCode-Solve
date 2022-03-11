/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init() { self.val = 0; self.left = nil; self.right = nil; }
 *     public init(_ val: Int) { self.val = val; self.left = nil; self.right = nil; }
 *     public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
 *         self.val = val
 *         self.left = left
 *         self.right = right
 *     }
 * }
 */
class Solution {
    
    var dic =  [ Int : [Int] ]()
    var depth = 0
    func dfs(_ root: TreeNode?, _ level: Int){
        if ( root == nil){
            return 
        }
        depth = max(depth, level)
        var tempArr = dic[level, default: []]
        tempArr.append(root!.val)
        dic[level] = tempArr
        dfs(root?.left, level + 1)
        dfs(root?.right, level + 1)
    }
    
    func levelOrder(_ root: TreeNode?) -> [[Int]] {
        
        if root == nil{
            return []
        }
        dfs(root, 0)
        
        var ans = [[Int]]()
        
        for index in 0..<(depth+1){
            ans.append(dic[index, default: []])
        }
        
        return ans
        
    }
}