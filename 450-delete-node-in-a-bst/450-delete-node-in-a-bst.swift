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
    var node: TreeNode?
    var left: TreeNode?
    var right: TreeNode?
    
    
    func inorderSucc(_ node: TreeNode?) -> TreeNode?{
        var cur = node
        while(cur?.left != nil){
            cur = cur?.left
        }
        return cur
    }
    func deleteNode(_ root: TreeNode?, _ key: Int) -> TreeNode? {
       if root == nil{
           return nil
       }
        
        if key == root!.val{
            if root?.left == nil && root?.right == nil{
                return nil
            }
            
            if root?.left == nil{
                return root?.right
            }
            
            if root?.right == nil{
                return root?.left
            }
            
            var sucss = inorderSucc(root?.right)
            root!.val = sucss!.val
            root?.right = deleteNode(root?.right, sucss!.val)
            
            
            
        }else if key > root!.val{
            root?.right = deleteNode(root?.right, key)
        }else if root!.val > key{
            root?.left = deleteNode(root?.left, key)
        }
        
        return root
    }
}