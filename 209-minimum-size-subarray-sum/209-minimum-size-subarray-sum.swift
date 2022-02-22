class Solution {
    func minSubArrayLen(_ target: Int, _ nums: [Int]) -> Int {
        var minLength = Int.max
        var windowStart = 0 
        var sum = 0
        for windowEnd in 0..<nums.count{
            sum += nums[windowEnd]
            
            while(sum >= target){
                minLength = min(minLength, windowEnd - windowStart + 1)
                sum -= nums[windowStart]
                windowStart += 1
            }
        }
        if minLength == Int.max{
            return 0
        }
        return minLength
    }
}