class Solution {
public:
    
    struct IndexElement{
        int label;
        bool isPrevSnake;
        int minStep;
        
        IndexElement(int label, bool isPrevSnake, int minStep){
            this->label = label;
            this->isPrevSnake = isPrevSnake;
            this->minStep = minStep;
        }
    };
     void mapIndices(vector<vector<int>> & board, map<int, pair<int,int> > &mp){
        int boardSize = board.size();
         
        int col = 0, row = boardSize - 1 ;
        
        int totalSize = 1;
        
        bool flip = false;
        
        while(row >= 0){
            mp[totalSize] = make_pair(row, col);
            
            if (!flip){
                 col ++;
            }else{
                 col --;
            }
           
            
            totalSize ++;
            
            if( col >= boardSize){
                col = boardSize - 1;
                flip = true;
                row -- ;
            }else if (col < 0 ){
                flip = false;
                col = 0;
                row --;
            }
        }
        
        
    }
    
    
    int bfs( vector<vector<int>> & board, map<int, pair<int,int> > &mp){
        queue<IndexElement> q;
        
        int n = board.size();
        
        q.push(IndexElement(1, false, 0));
        vector< int > vis(n * n + 10, 0);
        

        
        while(!q.empty()){
            
            int qSize = q.size();
            
            for(int index = 0; index < qSize; index ++ ){
                IndexElement front = q.front();
                
                q.pop();
                
                int step = front.minStep;
                int label = front.label;
                bool isPrevSnake = front.isPrevSnake;
                
                int limit = n * n ;
                
                int range = min(label + 6, limit );
                
                for(int start = label + 1; start <= range ; start ++ ){
                    int curLabel = start ;
                    // cout << curLabel << endl;
                    int curX = mp[curLabel].first;
                    int curY = mp[curLabel].second;
                    
                    if(curLabel == limit ){
                        return step + 1;
                    }
                     
                    if ( (board[curX][curY] == -1 ) && !vis[curLabel]){
                         vis[curLabel] = 1;
                        q.push(IndexElement(curLabel, false, step + 1));
                    }else if (board[curX][curY] != -1  &&   !vis[curLabel]){
                        vis[curLabel] = 1;
                        int jumpLabel = board[curX][curY];
                        
                        if(jumpLabel == limit ){
                            return step + 1;
                         }
                        
                        // if(!vis[jumpLabel]){
                        //     vis[jumpLabel] = 1;
                            q.push(IndexElement(jumpLabel, true, step + 1));
                        // }
                        
                    }
                }
            }  
        }
        
        return - 1;
    }
    
   
    
    int snakesAndLadders(vector<vector<int>>& board) {
        map<int, pair<int,int> > mp;
        
        mapIndices(board, mp);
        
        // int n = board.size();
        
        // for(int index = 1; index <= (n * n); index++ ){
        //     cout << mp[index].first << " " << mp[index].second << endl; 
        // }
        
        return bfs(board, mp);
    }
};