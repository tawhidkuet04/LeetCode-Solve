class Solution {
    func firstUniqChar(_ s: String) -> Int {
        var str = Array(s)
        var dictCount = [Character : Int](), dictIndex =  [Character : Int]() 
        var ans = str.count
        
        for index in 0..<str.count{
            dictIndex[str[index], default: 0] = index
            dictCount[str[index], default: 0 ] += 1
        }
        
        for (key, val) in dictCount{
            if val == 1{
                ans = min(ans, dictIndex[key, default:0])
            }
        }
        
        if ans == str.count{
            return -1
        }
        
        return ans
    }
}