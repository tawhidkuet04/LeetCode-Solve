class Solution {
    
    func isEveryCharAvailable( _ sMap: [Character: Int], _ tMap: [Character: Int] ) -> Bool{
        for (key,val) in tMap{
            if sMap[key, default: 0] < val{
                return false
            }
        }
        return true
    }
    
    func minWindow(_ s: String, _ t: String) -> String {
        var sMap = [Character: Int](), tMap = [Character: Int]()
        var sArr = Array(s), tArr = Array(t)
        var left = 0, right = 0 , minVal = Int.max, start = -1, end = 0, ans = ""
        
        for char in tArr{
            tMap[char, default: 0] += 1
        }
        
        while( left <= right && right < sArr.count){
            
            if !isEveryCharAvailable( sMap, tMap){
                sMap[sArr[right], default: 0] += 1
                
            }
        
            while (isEveryCharAvailable( sMap, tMap) && right < sArr.count){
                if minVal >= (right - left + 1){
                     minVal = (right - left + 1)
                     start = left
                     end = right
                }
               
                sMap[sArr[left], default: 0] -= 1
                left += 1
            
            }
            
            right += 1
        }
        
        if start == -1{
            return ans
        }
        for index in start..<(end+1){
            ans += String(sArr[index])
        } 
        return ans
        
        
    }
}