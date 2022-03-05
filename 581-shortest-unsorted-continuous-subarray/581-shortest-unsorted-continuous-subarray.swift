class Solution {
    func findUnsortedSubarray(_ nums: [Int]) -> Int {
        var minVal = nums[nums.count - 1], maxVal = nums[0]
        
        var left = nums.count - 1, right = 0, leftIndex = 0, rightIndex = 0
        
        while( left >= 0 || right < nums.count){
            if left >= 0{
                minVal = min(minVal, nums[left])
                if (minVal != nums[left]){
                    leftIndex = left
                }
                 left -= 1
            }
            
            if right < nums.count{
                maxVal = max(maxVal, nums[right])
                if (maxVal != nums[right]){
                    rightIndex = right
                }
                  right += 1
            }
        }
        
        if ( leftIndex >= rightIndex){
            return 0
        }
        
        return (rightIndex - leftIndex + 1)
        
    }
}
