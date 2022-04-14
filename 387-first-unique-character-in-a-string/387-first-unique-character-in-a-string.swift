class Solution {
    func firstUniqChar(_ s: String) -> Int {
        var str = Array(s)
        var dictCount = [Character : Int](), dictIndex =  [Character : Int]() 
        var ans = str.count
        
        for index in 0..<str.count{
            dictIndex[str[index], default: 0] = index
            dictCount[str[index], default: 0 ] += 1
        }
        
        for index in 0..<str.count{
            if dictCount[str[index], default: 0] == 1{
               return index
             }
        }
        
        return -1
    }
}