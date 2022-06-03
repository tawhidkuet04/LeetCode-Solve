class TicTacToe {
private:
   int n;
   vector<int> rows, cols;
    int diagleft = 0;
    int diagRight = 0;
    
public:
    TicTacToe(int n) {
        rows.assign(n,0);
        cols.assign(n,0);
        this->n = n;
    }
    
    int move(int row, int col, int player) {
        int curPlayer = (player == 1) ? 1 : -1;
       rows[row] += curPlayer;
       cols[col] += curPlayer;
       
       if(row == col){
           diagleft += curPlayer;
       }
        
       if( row + col == n - 1){
            diagRight += curPlayer;
       }
        
        if( abs(rows[row]) == n || abs(cols[col]) == n || abs(diagleft) == n || abs(diagRight) == n) {
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