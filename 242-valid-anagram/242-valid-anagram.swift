class Solution {
    func isAnagram(_ s: String, _ t: String) -> Bool {
    
    guard  s.count == t.count else{
        return false
    }
    
    var map = [Character: Int]()

    for char in s{
        map[char, default: 0] += 1
    }
    
    for char in t{
         map[char, default: 0] -= 1
        if map[char, default: 0] < 0{
            return false
        }
        
    }
    
    return true
}
}