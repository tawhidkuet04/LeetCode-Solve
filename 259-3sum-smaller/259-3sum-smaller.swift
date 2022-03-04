class Solution {
    
    func threeSumSmaller(_ nums: [Int], _ target: Int) -> Int {
        var ans = 0, arr = nums
        arr.sort()

        if nums.count < 3{
            return 0
        }
        for i in 0..<arr.count-2{
           var en = arr.count - 1
           for j in (i+1)..<arr.count-1{
               var sum = arr[i] + arr[j]
               while ((sum + arr[en]) >= target && en > 0){
                   en -= 1
               }
               // print("\(en) \(j)")
               if en > j{
                   ans += en - j
               }
               
           }
            
        }
        return ans
        
    }
}