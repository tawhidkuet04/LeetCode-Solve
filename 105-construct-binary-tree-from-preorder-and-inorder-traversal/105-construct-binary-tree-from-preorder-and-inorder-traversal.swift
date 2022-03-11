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
    
    var index = 0
    var map = [Int: Int]()
    
    func buildBinaryTree(_ preorder: [Int], _ inorder: [Int], _ root: TreeNode?, _ left: Int, _ right: Int) -> TreeNode?{
    
        if ( left > right){
            return nil
        }
        
        var node = TreeNode(preorder[index])
        var rootIndex = map[preorder[index], default: 0]
        index += 1
        node.left = buildBinaryTree(preorder, inorder, node.left, left ,rootIndex - 1)
        node.right = buildBinaryTree(preorder, inorder, node.right, rootIndex + 1, right)
        
        return node
        
        
    } 
    
    func buildTree(_ preorder: [Int], _ inorder: [Int]) -> TreeNode? {
        
        for index in 0..<inorder.count{
            map[inorder[index], default: 0] = index
        }
        
        return buildBinaryTree(preorder, inorder, nil, 0, inorder.count - 1)
        
    }
}