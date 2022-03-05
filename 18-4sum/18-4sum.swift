class Solution {
    func fourSum(_ nums: [Int], _ target: Int) -> [[Int]] {
        var ans = [[Int]](), arr = nums, right = nums.count - 1
        
        if nums.count < 4{
            return []
        }
        
        arr.sort()
        // 2 2 2 2 2 
        for i in 0..<arr.count - 3{
           
            if i == 0 || arr[i-1] != arr[i]{
               
              for j in (i+1)..<arr.count-2{
              if j == (i+1) || arr[j] != arr[j-1]{
                  right = arr.count - 1
                 for k in (j+1)..<arr.count-1{
                 if k == (j+1) || arr[k] != arr[k-1]{
                    var sum = arr[i] + arr[j] + arr[k] 
                    
                    while(((arr[right] + sum) > target) && right > k){
                        right -= 1
                    }
                    if( (arr[right] + sum) == target && right > k){
                        var quadArr = [arr[i], arr[j], arr[k], arr[right]]
                        ans.append(quadArr)
                      }
                }
             }
            }
                
            }
            }
            // -2 -1 0 0 1 2
           
        }
        
        
        return ans
    }
}