class Solution {
    func firstMissingPositive(_ nums: [Int]) -> Int {
        var arr = nums
        var size = nums.count
        
        for index in 0..<arr.count{
            if arr[index] < 0 || arr[index] > size{
                arr[index] = 0
            }
        }
        
        for index in 0..<arr.count{
            var newIndex = abs(arr[index])
            print(newIndex)
            if newIndex > 0  && newIndex <= arr.count{
                if arr[newIndex - 1] == 0{
                arr[newIndex - 1] = -(arr.count + 1)
                }else if arr[newIndex - 1] > 0 {
                     arr[newIndex - 1] *= -1
                }
            }
            
        }
        print(arr)
        for index in 0..<arr.count{
            if arr[index] >= 0 && arr[index] <= arr.count{
                return index + 1
            }
        }
        
        return arr.count + 1
    }
}