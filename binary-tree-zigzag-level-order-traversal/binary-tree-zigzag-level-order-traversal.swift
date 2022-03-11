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
    
    var dic = [Int: [Int]]()
    
    func dfs(_ root: TreeNode?, _ depth: Int){
        if root == nil{
            return
        }
        var temp = dic[depth, default: []]
        temp.append(root!.val)
        dic[depth] = temp
        dfs(root?.left, depth + 1) 
        dfs(root?.right, depth + 1)
        
    } 
    
    func zigzagLevelOrder(_ root: TreeNode?) -> [[Int]] {
        
        dfs(root, 0)
        
        var ans = [[Int]]()
        var index = 0
        for key in dic.keys.sorted{ $0 < $1}{
            var temp = [Int]()
            temp = dic[key, default: []]
            if index % 2 == 1 {
                temp =  temp.reversed()
            }
            // print(temp)
            ans.append( temp )
            index += 1
        }
        return ans
    }
}