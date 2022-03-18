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

    var ans = Int.min

    func maxSum(_ root: TreeNode?) -> Int{
        if root == nil{
            return 0
        }
        // if root != nil && root?.left  == nil && root?.right == nil{
        //     return root!.val
        // }
        
        var left = root!.val + maxSum(root?.left)
        var right =  root!.val + maxSum(root?.right)
       
        ans = max( ans, max( root!.val, max( max(left, right) , (left + right) - root!.val)))
        print("\(root!.val)  \(left) ----- \(right)    \(ans)")
        return max(max(left, right), root!.val)
        
    }
    func maxPathSum(_ root: TreeNode?) -> Int {
        var x = maxSum(root)
        return ans
    }
}