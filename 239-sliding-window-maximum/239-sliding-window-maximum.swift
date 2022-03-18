class Solution {
    
    func cleanDeque(_ deque: inout [Int], _ index: Int, _ k : Int, _ nums: [Int]){
        if !deque.isEmpty && deque.first! <= index - k{
                deque.removeFirst()
            }
            
            while( !deque.isEmpty && nums[deque.last!] < nums[index]){
                deque.removeLast()
            }
    }
    func maxSlidingWindow(_ nums: [Int], _ k: Int) -> [Int] {
        
        var deque = [Int]()
        var ans = [Int]()
        for index in 0..<k-1{
            
            cleanDeque( &deque, index, k, nums)
            deque.append(index)
        }
        for index in (k-1)..<nums.count{
            
            cleanDeque( &deque, index, k, nums)
            deque.append(index)
            ans.append(nums[deque.first!])
            
        }
        
        return ans
        
    }
}