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
    
    func buildBST(_ nums: [Int], _ root: TreeNode?, _ left: Int, _ right: Int) -> TreeNode?{
        if ( left > right){
            return nil
        }
        
        var mid = ( left + right) / 2
        var node = TreeNode(nums[mid])
        node.left = buildBST(nums, node.left, left, mid - 1)
        node.right = buildBST(nums, node.right, mid + 1 , right)
        
        return node
        
    }
    
    func sortedArrayToBST(_ nums: [Int]) -> TreeNode? {
        
        return buildBST(nums, nil, 0, nums.count - 1)
        
    }
}