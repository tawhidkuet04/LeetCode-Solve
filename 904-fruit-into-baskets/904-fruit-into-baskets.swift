class Solution {
    func totalFruit(_ fruits: [Int]) -> Int {
        var windowStart = 0 , windowEnd = 0 , mx = 0 , count = 0
        var mp = [Int: Int]()
        
        for windowEnd in 0..<fruits.count{
          let  val =  mp[fruits[windowEnd], default: 0 ]
        
          mp[fruits[windowEnd], default: 0 ] = val + 1
            
            
            
            if mp.count <= 2{
                mx = max(mx, windowEnd - windowStart + 1)
            }else{
                while( mp.count > 2){
                     mp[fruits[windowStart], default: 0 ] -= 1
                     if mp[fruits[windowStart], default: 0 ] == 0 {
                         mp.removeValue(forKey: fruits[windowStart])
                     }
                    
                    windowStart += 1
                }
            }
        }
        
        
        return mx
        
        
    }
}

