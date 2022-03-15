class Solution {
    
    var upper = -1, lower = -1
    func upperBound( _ nums: [Int], _ lo: Int, _ hi: Int, _ target: Int){
        var lo = lo, hi = hi
        while( lo <= hi){
            var mid = (lo + hi) / 2
            
            if nums[mid] == target{
                upper = mid 
                lo = mid + 1
            }else if nums[mid] > target{
                hi = mid - 1
            }else{
                lo = mid + 1
            }
            
            
        }
    }
    
      func lowerBound( _ nums: [Int], _ lo: Int, _ hi: Int, _ target: Int){
        var lo = lo, hi = hi
        while( lo <= hi){
            var mid = (lo + hi) / 2
            
            if nums[mid] == target{
                lower = mid 
                hi = mid - 1
            }else if nums[mid] > target{
                hi = mid - 1
            }else{
                lo = mid + 1
            }
            
            
        }
    }
    
    func searchRange(_ nums: [Int], _ target: Int) -> [Int] {
        upperBound(nums, 0, nums.count - 1, target)
        lowerBound(nums, 0, nums.count - 1, target)
    
        var ans = [lower, upper]

        return ans
        
    }
}