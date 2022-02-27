class Solution {
    func longestOnes(_ nums: [Int], _ k: Int) -> Int {
        var windowStart = 0, mx = 0, zeroCount = 0 
        for windowEnd in 0..<nums.count{
            if nums[windowEnd] == 0{
                zeroCount += 1
            }
            if zeroCount <= k{
                mx = max(mx, windowEnd - windowStart + 1)
            }else{
                while(zeroCount > k){
                    if (nums[windowStart] == 0){
                        zeroCount -= 1
                    }
                    windowStart += 1
                }
            }
        }
        return mx
        
    }
}