class Solution {
    func totalFruit(_ fruits: [Int]) -> Int {
        var windowStart = 0 , windowEnd = 0 , mx = 0 , count = 0
        var mp = [Int: Int]()
        
        for windowEnd in 0..<fruits.count{
          let  val =  mp[fruits[windowEnd], default: 0 ]
                if val == 0 {
                    count += 1 
                }
                 mp[fruits[windowEnd], default: 0 ] = val + 1
            
            
            
            if count <= 2{
                mx = max(mx, windowEnd - windowStart + 1)
            }else{
                while( count > 2){
                     mp[fruits[windowStart], default: 0 ] -= 1
                    let val = mp[fruits[windowStart], default: 0 ]
                        if val == 0 {
                            count -= 1 
                        } 
                    
                    windowStart += 1
                }
            }
        }
        
        
        return mx
        
        
    }
}

