class Solution {
    
    var upper = -1, lower = -1

    
      func findBound( _ nums: [Int], _ lo: Int, _ hi: Int, _ target: Int,_ isFirst: Bool){
        var lo = lo, hi = hi
        while( lo <= hi){
            var mid = (lo + hi) / 2
            
            if nums[mid] == target{
                if isFirst{
                    lower = mid 
                    hi = mid - 1
                }else{
                    upper = mid 
                    lo  = mid + 1
                }
                
            }else if nums[mid] > target{
                hi = mid - 1
            }else{
                lo = mid + 1
            }
            
            
        }
    }
    
    func searchRange(_ nums: [Int], _ target: Int) -> [Int] {
        findBound(nums, 0, nums.count - 1, target, true)
         findBound(nums, 0, nums.count - 1, target, false)
    
        var ans = [lower, upper]

        return ans
        
    }
}