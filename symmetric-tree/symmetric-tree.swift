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
    
    func checkSym(_ left: TreeNode?, _ right: TreeNode?) -> Bool{
        if left == nil && right == nil{
            return true
        }
        if left == nil || right == nil{
            return false
        }
        
        if left!.val != right!.val{
            return false
        }
        
        return checkSym(left?.left, right?.right) &&  checkSym(left?.right, right?.left)
       
    }
    
    
    func isSymmetric(_ root: TreeNode?) -> Bool {
        return checkSym(root?.left, root?.right)
    }
}