class Solution {
    

    func threeSumClosest(_ nums: [Int], _ target: Int) -> Int {
        
        var total = 0
        
        var arr = nums
        arr.sort()
        var mn = Int.max
        
        for index in 0..<arr.count{
           var lo = index + 1, hi = arr.count - 1
            while (lo < hi){
                let sum = arr[index] + arr[hi] + arr[lo]

                if (target > sum){
                    lo += 1
                }else{
                    hi -= 1
                }

                var dif = target - sum

                if ( abs(dif) < mn){
                    mn = abs(dif)
                    total = sum 
                }
            }
        }
        
        return total
        
    }
}