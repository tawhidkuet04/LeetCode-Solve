class Solution {
    func firstUniqChar(_ s: String) -> Int {
        var str = Array(s)
        var dictCount = [Character : Int](), dictIndex =  [Character : Int]() 
        var ans = str.count
        
//         for index in 0..<str.count{
//             dictIndex[str[index], default: 0] = index
//             dictCount[str[index], default: 0 ] += 1
//         }
        
//         for index in 0..<str.count{
//             if dictCount[str[index], default: 0] == 1{
//                return index
//              }
//         }
        
        var index = 0
        for char in s{
            dictIndex[char, default: 0] = index
            dictCount[char, default: 0 ] += 1
            index += 1
        }

        index = 0
        for char in s{
            if dictCount[char, default: 0] == 1{
               return index
             }
            index += 1
        }
        
        return -1
    }
}