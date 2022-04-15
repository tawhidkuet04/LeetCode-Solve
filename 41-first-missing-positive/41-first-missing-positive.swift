class Solution {
    func firstMissingPositive(_ nums: [Int]) -> Int {
        var set = Set<Int>()
        var negNumCount = 0
        var flag = 0
        
        for num in nums{
            if num <= 0 || num > nums.count{
                set.insert(0)
                flag = 1
            }else{
                set.insert(num)
            }
            if num < 0{
                negNumCount += 1
            }
            
        }
        
        if set.count == nums.count && flag == 0{
            return nums.count + 1
        }
        
        if negNumCount == nums.count{
            return 1
        }
        
        for index in 1...nums.count{
            if !set.contains(index){
                return index
            }
        }
        
        return 0
        
    }
}