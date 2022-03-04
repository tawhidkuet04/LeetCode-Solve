class Solution {
    func binSearch(_ lo: Int, _ hi: Int, _ target: Int, _ nums: [Int]) -> Int{
        var mid = 0
        var index = lo
        var lo =  lo, hi = nums.count - 1
        while(lo < hi){
            mid = (lo + hi + 1)/2
            if (nums[mid] >= target){
               
                hi = mid - 1 
            }
            else{
                index = mid
                lo = mid 
            }
            
        }
        
        return index
        
    }
    // 2 3 4 6 
    func threeSumSmaller(_ nums: [Int], _ target: Int) -> Int {
        var arr = nums, ans = 0
        arr.sort()
        if nums.count < 3{
            return 0
        }
        for i in 0..<(arr.count - 2){
            for j in (i+1)..<(arr.count - 1){
                let sum = arr[i] + arr[j]
                let dif = target - sum
                
                var range = binSearch(j, arr.count, dif, arr)
               
                ans += range - j
                
                
                // 1 2 3 
                 
                // if range == nums.count - 1 &&  nums[range] < dif {
                //     ans += 1
                // }
                
                
            }
        }
        
        return ans

    }
}