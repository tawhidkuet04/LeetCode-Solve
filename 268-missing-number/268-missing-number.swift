class Solution {
    func missingNumber(_ nums: [Int]) -> Int {
        var arr = nums
        var size = nums.count
        var oneFound = 0 
        
        for index in 0..<arr.count{
            if arr[index] == 1{
                oneFound += 1
            }
        }
        
        if oneFound == 0 {
            return 1
        }
        
        
        
        for index in 0..<arr.count{
            if arr[index] <= 0 || arr[index] > size{
                arr[index] = 1
            }
        }
        
        for index in 0..<arr.count{
            var newIndex = abs(arr[index])
            arr[newIndex - 1] = -1 * abs(arr[newIndex - 1])
        }
        
        
        for index in 0..<arr.count{
            if arr[index] > 0{
                return index + 1
            }
        }
        
        return 0
    }
}