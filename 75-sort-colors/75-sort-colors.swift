class Solution {
    func sortColors(_ nums: inout [Int]) {
        var zero = 0, left = 0, right = nums.count - 1,  one = 0
        
       zero = nums.reduce(0){  $0 + (($1 == 0) ? 1 : 0)}
       one = nums.reduce(0){  $0 + (($1 == 1) ? 1 : 0)}
        // print(one)
       left = zero 
        var index = 0 
        while(index < zero){
            nums[index] = 0
            index += 1
        }
        let oneIndex = left + one
        while(left < oneIndex){
            nums[left] = 1
            left += 1
        }
        right = oneIndex
        while(right < nums.count){
            nums[right] = 2
            right += 1
        }
    }
}