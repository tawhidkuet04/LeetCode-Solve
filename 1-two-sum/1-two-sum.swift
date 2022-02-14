class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var dict = [Int:Int]()
       
        var ans: [Int] = []
        
        for i in 0..<nums.count{
            var anotherNum = target - nums[i]
            if let  value = dict[anotherNum]{
               dict[anotherNum] = 0
              if value != i {
                ans.append(i)
                ans.append(value)
                return ans
               }
            }
             dict[nums[i]] = i
        }
        
        return []
    }
}
