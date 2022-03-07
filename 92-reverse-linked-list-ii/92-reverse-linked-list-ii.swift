/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init() { self.val = 0; self.next = nil; }
 *     public init(_ val: Int) { self.val = val; self.next = nil; }
 *     public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
 * }
 */
class Solution {
    func reverseBetween(_ head: ListNode?, _ left: Int, _ right: Int) -> ListNode? {
        
        var startNode : ListNode?
        var endNode : ListNode?
        if left == right{
            return head
        }
        var prev: ListNode? = head, cur = head, next = head?.next, count = 1
        
        while(next != nil){
            if( count >= left && count < right){
                if count == left{
                    startNode = prev
                     endNode = cur
                }
                next = cur?.next
                cur?.next = prev
                prev = cur 
                cur = next
                
            }else if(count == right){
                
                next = cur?.next
                cur?.next = prev
                prev = cur 
                cur = next
                
                startNode?.next = prev
                endNode?.next = next
                
                if left == 1{
                    return prev
                }
            }else{
                prev = cur 
                next = cur?.next
                cur = next
            }

            count += 1
        }
        // print(count)
        if left == 1 && right == count - 1{
            return prev
        }
        return head
        
    }
}

// 1 2 3 4 5
// 2 3 4 5 1