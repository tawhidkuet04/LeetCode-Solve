class TicTacToe {
private:
    int board[102][102];
    int size;
    
public:
    TicTacToe(int n) {
        size = n;
    }
    
    int move(int row, int col, int player) {
        board[row][col] = player;
        
        int colCount = 0, rowCount = 0, diagLeft = 0, diagRight = 0;
        
        int diagRowUp = 0, diagRowDown = size - 1;
        for(int index = 0; index < size; index ++ ){
            if(board[row][index] == player){
                colCount ++ ;
            }
            
             if(board[index][col] == player){
                rowCount ++ ;
            }
            if(board[diagRowUp++][index] == player){
                diagLeft ++ ;
            }
             if(board[diagRowDown--][index] == player){
                diagRight ++ ;
            }
        }
        
        if(colCount == size || rowCount == size || diagLeft == size || diagRight == size ){
            return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */