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
       rows[row] =  (player == 1) ? ( rows[row] + 1 ) : ( rows[row] -1);
       cols[col] =  (player == 1) ? ( cols[col] + 1 ) : ( cols[col] -1);
       
       if(row == col){
           diagleft = (player == 1) ? (diagleft + 1 ) : ( diagleft - 1);
       }
        
       if( row + col == n - 1){
            diagRight = (player == 1) ? (diagRight + 1 ) : ( diagRight - 1);
       }
        
        // cout <<  n << endl;
        if( rows[row] == n || cols[col] == n || diagleft == n || diagRight == n ){
            return 1;
        }else if( abs(rows[row]) == n || abs(cols[col]) == n || abs(diagleft) == n || abs(diagRight) == n) {
            cout << rows[row] << endl;
            return 2;
        }
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */