class Solution {
    func isPalindrome(_ s: String) -> Bool {
    var ans = Array(s.lowercased()).filter({$0.isNumber || $0.isLetter})
    
    return ans == (ans.reversed())
        
   }


}