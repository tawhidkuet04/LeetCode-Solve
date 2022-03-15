class Solution {
    
    var ans = 0
    func findPeak(_ arr: [Int], _ left: Int, _ right: Int){
      
        if left >= right{
            return 
        }
        
        var mid = (left + right) / 2
        
        if  arr[mid + 1] > arr[mid]{
             ans = mid + 1
             findPeak(arr , mid + 1 , right)
        }else  {
             findPeak(arr, left , mid)
        } 
        
        
        
    }
    
    func findPeakElement(_ nums: [Int]) -> Int {

        findPeak(nums, 0, nums.count - 1)
        return ans
        
    }
}