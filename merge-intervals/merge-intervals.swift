class Solution {
    func merge(_ intervals: [[Int]]) -> [[Int]] {
        var intervalArr = [(Int, Int)]()
        
        for array in intervals{
            intervalArr.append( (array[0], array[1]))
        }
        
        intervalArr.sort{ $0.0 < $1.0 }
        
        var ans = [[Int]]()
        
        var interval = (intervalArr[0].0, intervalArr[0].1)
        
        for (first, second) in intervalArr{
            if interval.1 >= first{
                interval.1 = max(interval.1, second)
            } else{
                ans.append([interval.0, interval.1])
                interval = (first, second)
            }
            
        }
        ans.append([interval.0, interval.1])
        return ans
    }
}