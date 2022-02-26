class Solution {
    
    func isRepeated(_ mp: [Character: Int]) -> Bool{
        for (key, val) in mp{
            if val > 1 {
                return true
            }
        }
        return false
    }
    
    func lengthOfLongestSubstring(_ s: String) -> Int {
        var inputArray = Array(s), windowStart = 0, mx = 0
        
        var mp = [Character: Int]()
        
        for windowEnd in 0..<inputArray.count{
            mp[inputArray[windowEnd], default: 0 ] += 1
            
            if  mp[inputArray[windowEnd], default: 0 ] <= 1{
               mx = max(mx, windowEnd - windowStart + 1) 
            }else{
                while(  mp[inputArray[windowEnd], default: 0 ] > 1){
                    mp[inputArray[windowStart], default: 0] -= 1
                    windowStart += 1
                }
            }
        }
        
        return mx
        
    }
}