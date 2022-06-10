class Solution {
public:



    int countBattleships(vector<vector<char>>& board) {

        int rowSize = board.size();
        int colSize = board[0].size();

        int ans = 0;

        for(int row = 0; row < rowSize; row ++ ){
            int count = 0;
            for(int col = 0; col < colSize; col ++ ){

                if(board[row][col] == 'X'){
                    int count = 0;
                    while(col < colSize && board[row][col] == 'X'){
                        if( (row != 0 && board[row - 1][col] == 'X') || ((row +1 ) < rowSize && board[row + 1][col] == 'X')){
                            count = 0;
                            break;
                        }
                        count ++ ;
                        col ++;
                    }
                    
                    if(count > 0){
                        ans += 1;
                    }
                }
            }
        }

        for(int col = 0; col < colSize; col ++ ){
            int count = 0;
            for(int row = 0; row < rowSize; row ++  ){
                
                
                if(board[row][col] == 'X'){
                    int count = 0;
                    while(row < rowSize && board[row][col] == 'X'){
                        if( (col != 0 && board[row][col - 1] == 'X') || ((col +1 ) < colSize && board[row][col  + 1] == 'X')){
                            count = 0;
                            break;
                        }
                        count ++ ;
                        row  ++;
                    }
                    
                    if(count > 1){
                        ans += 1;
                    }
                }
                
                
            }
        }

        return ans;

    }
};

//   X . . X
// ..
//   X .  X
//   X. X . X
//   .......
//   X X X X


//   Time O(N * M)
//   Space O(1) + O(Depth) // 


//   1 1 1 0 0 1 1 1 

//   O(N*M) + O(N*M) 
//   O(1) 

//   1*1