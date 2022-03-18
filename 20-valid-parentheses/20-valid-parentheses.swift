class Solution {
    func isValid(_ s: String) -> Bool {
        var stack = [Character]()
        var sArr = Array(s)
        var mp = [Character: Character]()

        
        mp[")"] = "("
        mp["}"] = "{"
        mp["]"] = "["
        
        for char in sArr{
            if char == "(" || char == "{" || char == "["{
                stack.append(char)
            }else if !stack.isEmpty && stack.last! == mp[char]{
                stack.removeLast()
            }else{
                return false
            }
        }
        
        if stack.count == 0{
            return true
        }else{
            return false
        }

    }
}