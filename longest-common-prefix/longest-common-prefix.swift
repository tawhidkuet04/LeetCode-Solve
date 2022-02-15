class Solution {
    func longestCommonPrefix(_ strs: [String]) -> String {
     
    var minSize: Int = 0
    if let min = strs.min{a,b in
        return a.count < b.count
    }{
        minSize = min.count
    }
    var countArr = Array(repeating: Array(repeating: 0, count: 26), count: minSize)
    for str in strs{
        let charArray = Array(str)
        for index in 0..<minSize{
            let char = charArray[index]
            if let aschiiVal = char.asciiValue{
                let charIndex = Int(aschiiVal - 97)
                let val = countArr[index][charIndex]
                countArr[index][charIndex] = val + 1
            }
        }
    }
    
    var prefixStr: String = ""
    for index in  0..<minSize{
        for charIndex in 0..<26{
            let val = countArr[index][charIndex]
            if val == strs.count{
                let u = UnicodeScalar(charIndex + 97)!
                prefixStr.append(Character(u))
                break
            }
        }
        if prefixStr.count - 1 != index{
           break
        }
    }
    
    return prefixStr
   
   }
       

      
}