class Solution {
    func sortColors(_ nums: inout [Int]) {
        var p0 = 0 , p2 = nums.count - 1, cur = 0
        
        while(cur <= p2){
             // print("\(p0) \(p2) \(cur)")
             if (nums[cur] == 0 ){
               
                nums.swapAt(p0, cur)
                p0 += 1
                cur += 1
            
            }else if (nums[cur] == 2){
                nums.swapAt(p2, cur)
                p2 -= 1
            }else{
                cur += 1
            }
        }
        
        
    }
}