class Solution {
    func sortedSquares(_ nums: [Int]) -> [Int] {
        var ans = Array(repeating: 0, count: nums.count)
        
        var left = 0, right = nums.count - 1, size = nums.count - 1
        
        for index in stride(from: size, through: 0, by: -1){
            var square = 0 
            if(abs(nums[left]) > abs(nums[right])){
                square = nums[left]
                left += 1
            }else{
                square = nums[right]
                right -= 1
            }
            ans[index] = square * square
        }
        
        return ans
    }
}
