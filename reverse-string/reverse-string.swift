class Solution {
    func reverseString(_ s: inout [Character]) {
        var size: Int = s.count / 2
        
        var i: Int = 0
        var j: Int = s.count - 1
        
        while (i < size){
            s.swapAt(i,j)
            i += 1
            j -= 1
        }
     }
}