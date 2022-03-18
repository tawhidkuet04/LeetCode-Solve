class Solution {
    func isValid(_ s: String) -> Bool {
        var stack = [Character]()
        var sArr = Array(s)
        
        
        for char in sArr{
            if char == "(" || char == "{" || char == "["{
                stack.append(char)
            }else if char == ")" && !stack.isEmpty && stack.last! == "("{ 
                 stack.removeLast()
            }else if char == "]" && !stack.isEmpty && stack.last! == "["{ 
                 stack.removeLast()
            }else if char == "}" && !stack.isEmpty && stack.last! == "{"{ 
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