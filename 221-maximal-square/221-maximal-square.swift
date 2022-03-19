class Solution {
    func maximalSquare(_ matrix: [[Character]]) -> Int {
        var dp = Array(repeating: Array(repeating: 0, count: matrix[0].count + 1), count: matrix.count + 1)
    var cumArr = Array(repeating: Array(repeating: 0, count: matrix[0].count), count: matrix.count)
        for row in 0..<matrix.count{
            for col in 0..<matrix[0].count{
                if matrix[row][col] == "0"{
                     cumArr[row][col] = 0
                }else{
                     cumArr[row][col] = 1
                }
               
            }
        }
        var ans = 0
        
        for row in 1..<dp.count{
            for col in 1..<dp[0].count{
                if cumArr[row - 1][col - 1] == 1{
                     dp[row][col] = min( min(dp[row - 1][col], dp[row][col - 1]) , dp[row - 1][col - 1]) + 1
                }else{
                    dp[row][col] = 0
                }
               
                ans = max( ans , dp[row][col])
            }
        }
        
        return ans * ans
        
      
}

    
}