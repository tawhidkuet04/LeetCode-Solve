/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public var val: Int
 *     public var left: TreeNode?
 *     public var right: TreeNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.left = nil
 *         self.right = nil
 *     }
 * }
 */

class Solution {
    
 
    
    func inorderSuccessor(_ root: TreeNode?, _ p: TreeNode?) -> TreeNode? {
        
        var currentNode = root
        var ans : TreeNode?
        
        while( currentNode != nil){
            if p!.val >= currentNode!.val {
                currentNode = currentNode?.right
            }else{
                ans = currentNode
                currentNode = currentNode?.left
            }
        }
        return ans
      
    }
}