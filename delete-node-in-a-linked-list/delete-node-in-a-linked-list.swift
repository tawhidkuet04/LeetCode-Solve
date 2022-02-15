/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.next = nil
 *     }
 * }
 */

class Solution {
 
    
    func deleteNode(_ node: ListNode?) {
         var nextNode = node?.next
         if let val =   nextNode?.val{
               node?.val =  val
               node?.next = nextNode?.next
         }
       
        
        
    }
}