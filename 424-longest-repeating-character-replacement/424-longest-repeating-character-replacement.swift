class Solution {
    
    func getReplacebleCharCount(_  dict:  [Character: Int], _ start: Int, _ end: Int)  -> Int{
        var mx = 0 
        for (key, val) in dict{
            mx = max(mx, val)
        }
        
        return (end - start + 1 ) - mx 
    }
    
    func characterReplacement(_ s: String, _ k: Int) -> Int {
        var windowStart = 0, mx = 0
        var inputString = Array(s)
        var dict = [Character: Int]()
        
        for windowEnd in 0..<inputString.count{
            dict[inputString[windowEnd], default: 0 ] += 1
            let replaceCharCount = getReplacebleCharCount(dict, windowStart, windowEnd)
            if replaceCharCount <= k{
                mx = max(mx, windowEnd - windowStart + 1 )
            }else{
                while(getReplacebleCharCount(dict, windowStart, windowEnd) > k){
                    dict[inputString[windowStart], default: 0 ] -= 1
                    windowStart += 1
                }
            }
    
        }
        return mx
    }
}
