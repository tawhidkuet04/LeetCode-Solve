class Solution {
    func productExceptSelf(_ nums: [Int]) -> [Int] {
        
        var ans = [Int]()

        ans.append(1)
        
        for index in 0..<(nums.count - 1){
            ans.append(nums[index] * ans[index])
        }
        
        var suf = 1, size =  nums.count - 1
        
        for index in stride(from: size, through: 0 , by: -1){
            ans[index] = suf * ans[index]
            suf = nums[index] * suf
        }
        
        return ans
        
    }
}

