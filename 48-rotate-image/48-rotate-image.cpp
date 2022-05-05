class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int matSize = matrix.size();

        
        
        for(int index = 0; index < matSize; index ++ ){
            for(int row = index; row < matSize ; row ++){
                swap(matrix[row][index], matrix[index][row]);
            }
            for(int row = 0; row < matSize /2 ; row ++ ){
                swap(matrix[index][row], matrix[index][matSize - row - 1]);
            }
        }
    }
};




// 1 4 7 1
// 2 5 8 1
// 3 6 9 1
// 1 1 1 1

  
// mat[row][index], mat[index][row]