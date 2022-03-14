class Solution {
    var ans = 0
    func partition(_ nums: inout [Int], _ left: Int, _ right: Int) -> Int{
        
        var pIndex = left
        var pivot = right
        
        for index in left..<right{
            if nums[index] <= nums[pivot]{
                nums.swapAt(index, pIndex)
                pIndex += 1
            }
        }
        nums.swapAt(pivot, pIndex)
        return pIndex
  
        
    }
    
    func quickSelect(_ nums: inout [Int], _ left: Int, _ right: Int, _ k: Int){
        if left >= right{
            return
        }
        
        var pivot = (left + right)/2
        var index = partition( &nums, left, right )
    
        if index == (nums.count - k){
             ans = index
             return
        }
        
        if index < (nums.count - k){
            quickSelect(&nums, index, right, k)
            
        }else if index > (nums.count - k){
            quickSelect(&nums, left, index - 1, k)
        }
      
    }
    
    func findKthLargest(_ nums: [Int], _ k: Int) -> Int {
        var arr = nums
        quickSelect( &arr, 0, nums.count - 1, k)
        print(arr)
        return arr[ans] 
    }
    
    
   
}