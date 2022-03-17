class Solution {
    func spiralOrder(_ matrix: [[Int]]) -> [Int] {
        var matrix = matrix
        var row = matrix.count, col = matrix[0].count, rowUp = 1, colUp = 0,
            x = 0, y = 0, firstTurn = false, secondTurn = false,
            thirdTurn = false
            
        var spiralArr = [Int]()

        
        while( spiralArr.count < (matrix.count * matrix[0].count) ){

             if !firstTurn{
                 spiralArr.append(matrix[x][y])
                 y += 1
                 if y >= col{
                     y = col - 1
                     x += 1
                     col -= 1
                     firstTurn = true
                 }
             }else if firstTurn && !secondTurn{
                  spiralArr.append(matrix[x][y])
                  x += 1
                  if x >= row{
                      x = row - 1
                      y -= 1
                      row -= 1
                      secondTurn = true
                  }
             }else if secondTurn && !thirdTurn{
                   spiralArr.append(matrix[x][y])
                   y -= 1
                   if y < colUp{
                       y = colUp 
                       x -= 1
                       thirdTurn = true
                   }
             }else{
                 spiralArr.append(matrix[x][y])
                  x -= 1
                 if x < rowUp{
                     colUp += 1
                     x = rowUp
                     y = colUp
                     print("\(x) \(y)")
                     
                     rowUp += 1
                     firstTurn = false
                     secondTurn = false
                     thirdTurn = false
                 }
             }
        }
        
        return spiralArr
    }
}