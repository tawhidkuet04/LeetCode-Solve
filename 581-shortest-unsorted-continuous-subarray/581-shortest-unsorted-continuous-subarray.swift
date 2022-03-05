class Solution {
    func findUnsortedSubarray(_ nums: [Int]) -> Int {
        
        var minArr = Array(repeating: 0, count: nums.count), maxArr = Array(repeating: 0, count: nums.count)
        
        var left = 0, right = nums.count - 1
        
        for index in 0..<nums.count{
            if index == 0{
                maxArr[index] = nums[index]
            }else{
                 maxArr[index] = max(maxArr[index - 1], nums[index])
            }
        }
       
        var end = nums.count - 1
        for index in stride(from: end, through: 0, by: -1){
            if index == end {
                minArr[index] = nums[index]
            }else{
              minArr[index] =  min(nums[index], minArr[ index + 1])
            }
        }
          // print("okk")
        var leftFlag = false, rightFlag = false
        while(left < right){
            if(minArr[left] == nums[left]){
                left += 1
            }else{
                 leftFlag = true
            }
            
            if (maxArr[right] == nums[right]){
                right -= 1
            }else{
                rightFlag = true
            }
            
            if(leftFlag && rightFlag){
                break
            }
           
            
        }
        
        if ( left >= right){
            return 0
        }
        
        return (right - left + 1)
        
    }
}
