class Solution {
    var ans = 0
    func partition(_ nums: inout [Int], _ left: Int, _ right: Int) -> Int{
        
        var pIndex = left - 1
        var pivot = right
        
        for index in left..<right{
            if nums[index] <= nums[pivot]{
                 pIndex += 1
                nums.swapAt(index, pIndex)
               
            }
        }
        nums.swapAt(pivot, pIndex + 1)
        return pIndex + 1
  
        
    }
    
    func quickSelect(_ nums: inout [Int], _ left: Int, _ right: Int, _ k: Int){
        if left >= right{
            return
        }
        
        var index = partition( &nums, left, right )
        
        if index == (nums.count - k){
             ans = index
             // return
        }
        
        // if index < (nums.count - k){
            quickSelect(&nums, index + 1, right, k)
            
        // }else if index > (nums.count - k){
            quickSelect(&nums, left, index - 1, k)
        // }
      
    }
    
    func findKthLargest(_ nums: [Int], _ k: Int) -> Int {
        var arr = nums
        quickSelect( &arr, 0, nums.count - 1, k)
        print(arr)
        return arr[nums.count - k] 
    }
    
    
   
}