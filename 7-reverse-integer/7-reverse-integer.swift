class Solution {

    
    func reverse(_ x: Int) -> Int {

        var temp: Int = 0
        var value: Int = 0
        var range: Int = 0
        if x < 0{
            temp = -1 * x
            value = temp
            range = -1 * Int(Int32.min)
        }else{
            temp =  x
            value = temp
            range = Int(Int32.max)
        }
        var ans: Int = 0
        while(value != 0){
            var mod = value % 10 ;
            value /= 10
            
            var maxVal = range/10
            
            if ans > maxVal{
                return 0
            }else if ans == maxVal{
                if mod > 7{
                    return 0
                }
            }
             ans = ans * 10 + mod 
            
        }
        return (x < 0 ) ? ans * -1 : ans        
    }
}