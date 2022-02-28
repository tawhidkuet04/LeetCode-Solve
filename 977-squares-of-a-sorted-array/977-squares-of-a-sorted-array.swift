class Solution {
    func sortedSquares(_ nums: [Int]) -> [Int] {
        var ans = [Int]()
        if nums[0] >= 0 {
            for num in nums{
                ans.append(num * num)
            }
            return ans
        }
        
        if nums[nums.count - 1 ] < 0 {
           for num in nums{
                ans.append(num * num)
            }
            ans.reverse()
            return ans
        }
        
        var leftP = 0, rightP = 0
        
        for index in 0..<nums.count{
            if (nums[index] >= 0) {
                leftP = index - 1
                rightP = index 
                break
            }
        }
        
        while( leftP >= 0 && rightP < nums.count){
            let leftValue =  nums[leftP] * nums[leftP]
            let rightValue = nums[rightP] * nums[rightP]
            
            if(leftValue >= rightValue){
                ans.append( rightValue )
                rightP += 1
            }else{
                ans.append( leftValue )
                leftP -= 1
            }
        }
        
        while(leftP >= 0){
            ans.append(nums[leftP] * nums[leftP])
            leftP -= 1
        }
        while(rightP < nums.count){
            ans.append(nums[rightP] * nums[rightP])
            rightP += 1
        }
        
        return ans
    }
}
