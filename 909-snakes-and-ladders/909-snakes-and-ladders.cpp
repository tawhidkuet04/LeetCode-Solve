class Solution {
public:
    
    pair<int,int> intToSquare(int label, int n ){
        
        int row = (label - 1)/n;
        int col = 0;
        
        if(row % 2){
            col = n - 1 - ((label - 1) % n );
        }else{
            col = (label - 1) % n ;
        }
        
        return make_pair(row, col);
        
    }
    int bfs( vector<vector<int>> & board){
        
        int n = board.size();
        
        vector< vector<int> > vis (n + 1 , vector<int>(n + 1 , 0) );
        
        vis[0][0] = 1;
        
        queue< int >  q;
        
        q.push(1);
        
        int step = 0 ;
        
        while(!q.empty()){
            int qSize = q.size();
            
            for(int index = 0; index < qSize; index ++ ){
                auto curSquare = q.front();
                q.pop();
                
                for(int label = curSquare + 1; label <= min(curSquare + 6, n * n ); label ++ ){
                   auto ind = intToSquare(label, n);
                    
                   int x = ind.first;
                   int y = ind.second;

                    
                    int nextSquare = label;
                    
                    if(board[x][y] != -1){
                        nextSquare = board[x][y];
                    }
                    
                    if(nextSquare == (n*n)){
                        return step + 1;
                    }
                    
                    if(!vis[x][y]){
                        vis[x][y] = 1;
                        q.push(nextSquare);
                    }
                }
                
               
                
            }
             step ++;
        }
        
        return -1 ;
        

    }
    
   
    
    int snakesAndLadders(vector<vector<int>>& board) {
        reverse(board.begin(), board.end());
        // for(int row = 0; row < board.size(); row ++ ){
        //     for(int col = 0; col < board.size(); col ++ ){
        //         cout << board[row][col] << " ";
        //     }
        //     cout << endl;
        // }
        return bfs(board);
    }
};