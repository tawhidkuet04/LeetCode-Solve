class Solution {
    
    func isContainsAnyChar(_ mp: [Character: Int]) -> Bool{
        let firstLetter = Unicode.Scalar("a")
        let lastLetter = Unicode.Scalar("z")
        var count = 0
        for val in firstLetter.value...lastLetter.value{
            if let char = Unicode.Scalar(val){
                // print(char)
                if mp[Character(char), default:0] == 0{
                    count += 1
                }
            }
        }
        return (count != 26)
    }
    
    func checkInclusion(_ s1: String, _ s2: String) -> Bool {
        if s2.count < s1.count {
            return false
        }
        var windowStart = 0, windowEnd = 0
        
        var mp = [Character: Int]()
        
        var s1Array = Array(s1), s2Array = Array(s2)
        
        for index in 0..<s1Array.count{
            mp[s2Array[index], default: 0] -= 1
            mp[s1Array[index], default: 0] += 1 
        }
        
        windowEnd = s1Array.count
        while( windowEnd < s2Array.count){
            if (!isContainsAnyChar(mp)){
                return true
            }else{
                
                mp[s2Array[windowStart], default :0] += 1
                mp[s2Array[windowEnd], default :0] -= 1
                
                windowStart += 1
                windowEnd += 1
            }
        }
        
        if (!isContainsAnyChar(mp)) {
            return true
        }
        else {
            return false
        }
    }
}