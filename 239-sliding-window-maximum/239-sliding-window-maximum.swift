class Solution {
    func maxSlidingWindow(_ nums: [Int], _ k: Int) -> [Int] {
        
        var deque = [Int]()
        var ans = [Int]()
        for index in 0..<k-1{
            if !deque.isEmpty && deque.first! <= index - k{
                deque.removeFirst()
            }
            
            while( !deque.isEmpty && nums[deque.last!] < nums[index]){
                deque.removeLast()
            }
            
            deque.append(index)
        }
        for index in (k-1)..<nums.count{
            
            if !deque.isEmpty && deque.first! <= index - k{
                deque.removeFirst()
            }
            
            while( !deque.isEmpty && nums[deque.last!] < nums[index]){
                deque.removeLast()
            }
            
            deque.append(index)
            ans.append(nums[deque.first!])
            
        }
        
        return ans
        
    }
}