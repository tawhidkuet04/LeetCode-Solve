class Solution {
    func titleToNumber(_ columnTitle: String) -> Int {
        var charArray = Array(columnTitle)
        
        var ans = 0
        var mul = 1
        
        charArray = charArray.reversed()
       
        for char in charArray{
            var aschii = Int(char.asciiValue!) - 65 + 1
            ans += (mul * aschii)
            mul *= 26
        }
        
        return ans
        
        

    }
}