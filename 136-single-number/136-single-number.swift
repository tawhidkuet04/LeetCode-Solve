class Solution {
    func singleNumber(_ nums: [Int]) -> Int {
        var xorValue: Int = 0
        for num in nums{
            xorValue ^= num
        }
        return xorValue
    }
}