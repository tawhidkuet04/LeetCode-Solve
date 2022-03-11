/**
 * Definition for a Node.
 * public class Node {
 *     public var val: Int
 *     public var left: Node?
 *     public var right: Node?
 *	   public var next: Node?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.left = nil
 *         self.right = nil
 *         self.next = nil
 *     }
 * }
 */

class Solution {
    

    
    func connect(_ root: Node?) -> Node? {
        
        if root == nil{
            return nil
        }
        var currentNode = root
        var node = root
        root?.next = nil
        while(node?.left != nil){
            currentNode = node
            while( currentNode != nil ){
                currentNode?.left?.next = currentNode?.right
                if currentNode?.next != nil{
                    currentNode?.right?.next = currentNode?.next?.left
                }
                currentNode = currentNode?.next
            }
            node = node?.left
        }
        
        
        return root
        
    }
}