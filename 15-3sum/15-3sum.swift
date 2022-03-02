class Solution {
    
    struct Index: Hashable{
        var first: Int = 0
        var second: Int = 0
        var third: Int = 0
    }
    func threeSum(_ nums: [Int]) -> [[Int]] {
        if nums.count < 3{
            return []
        }
        
       var hashSet = [Int: [Int]]()
       var ans = [[Int]]()
       for index in 0..<nums.count{
           hashSet[nums[index], default: [Int]() ].append(index)
       }
        
        
       var vis =  [Index: Int]()
       for i in 0..<nums.count{
           for j in (i+1)..<nums.count{
               let val = hashSet[ -1 * (nums[j] + nums[i])]
                
               if let  val = val{
                   let otherVal = nums[val[val.count-1]]
                   var triArr = [Int]()
                   triArr.append(otherVal)
                   triArr.append(nums[i])
                   triArr.append(nums[j])
                   triArr.sort()
                   // print(vis[Index(first: triArr[0], second: triArr[1], third: triArr[2])] )
                   if (vis[Index(first: triArr[0], second: triArr[1], third: triArr[2])] == nil && i != j && j != val[val.count - 1] && i != val[val.count - 1]){
                       // print("\(i) \(j) \(val[val.count - 1])")
                       ans.append(triArr)
                       vis[Index(first: triArr[0], second: triArr[1], third: triArr[2])] = 1
                   }
               }
           }
       } 
        
        return ans

    }
}