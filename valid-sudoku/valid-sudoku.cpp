class Solution {
public:
    
   bool checkSudokoMap( int sudokoMap[]){
      for(int i = 1; i < 10 ; i ++){
           if(sudokoMap[i] > 1){
            return false;
           }
       }
      return true;
    }

    bool isValidBox(vector< vector<char> > & board, int row, int col){
      int sudokoMap[10] = {0};
        for(int i = row; i < row + 3; i ++){
          for(int j = col; j < col + 3; j ++){
             if( board[i][j] != '.'){
             sudokoMap[ board[i][j] - '0'] ++;
            }
          }
        }
           return checkSudokoMap(sudokoMap);
    }

   bool isValidRow(vector< vector<char> > & board, int row){
    int sudokoMap[10] = {0};
    
    for(int i = 0; i < 9 ; i ++){
        if(board[row][i] != '.'){
         sudokoMap[board[row][i] - '0']++;
        }
     }

    return checkSudokoMap(sudokoMap);
   }

    bool isValidColoumn(vector< vector<char> > & board, int col){
       int sudokoMap[10]={0};

       for(int i = 0; i < 9; i ++){
         if(board[i][col] != '.'){
            sudokoMap[board[i][col] - '0']++;
         }

       }
        return checkSudokoMap(sudokoMap);
    
    }

    
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0 ; i < 9 ; i += 3){
          for(int j = 0 ; j < 9 ; j +=3){
            if(!isValidBox(board, i, j)){
               return false;
             }
          }
        }

        for(int i = 0 ; i < 9 ; i ++){
           if(!isValidRow(board, i)){
             return false;
           }
           if(!isValidColoumn(board, i)){
             return false;
           }
        }

        return true;


    }
};

