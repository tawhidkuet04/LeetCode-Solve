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
    
    func insert(_ root: TreeNode?, _ val: Int) -> TreeNode?{
        if root == nil{
            return TreeNode(val)
        }
        
        if (val < root!.val){
            root?.left = insert(root?.left, val)
        }else{
            root?.right = insert(root?.right, val)
        }
        return root
    }
    func insertIntoBST(_ root: TreeNode?, _ val: Int) -> TreeNode? {
        return insert(root, val)
    }
}