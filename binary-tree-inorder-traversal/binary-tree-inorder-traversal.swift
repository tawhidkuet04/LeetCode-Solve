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
    var ans = [Int]()
    
    func inorder(_ root: TreeNode?){
        if root == nil{
            return 
        }
        inorder(root?.left)
        ans.append(root!.val)
        inorder(root?.right)
    }
    
    func inorderTraversal(_ root: TreeNode?) -> [Int] {
        if root == nil{
            return []
        }
        inorder(root)
        return ans
    }
}