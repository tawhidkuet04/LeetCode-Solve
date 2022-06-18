class Solution {
public:
    
    bool isValid(int row, int col, vector<vector<int>>& grid, vector<vector<int>> &vis){
        if( row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() &&
          grid[row][col] == 0 && vis[row][col] == 0){
            return true;
        }
        
        return false;
    }
    
    void bfs(vector<vector<int>>& grid,
           vector<vector<int>>& dis,  queue< pair<int,int> > q,
              vector<vector<int>>& count, vector<vector<int>>& diss){
        int fx[4] = {0,0,1,-1};
        int fy[4] = {1,-1,0,0};
        int sourceX= q.front().first;
        int sourceY = q.front().second;
        
         while(!q.empty()){
             auto front = q.front();
             q.pop();
             
             for(int index = 0; index < 4; index ++ ){
                 int newRow = front.first + fx[index];
                  int newCol = front.second + fy[index];
                 
                 if(isValid(newRow, newCol, grid, dis)){
                     // vis[newRow][newCol] = 1;
                     // cout <<  dis[front.first][front.second] << endl;
                     dis[newRow][newCol]  = dis[front.first][front.second] + 1;
                     diss[newRow][newCol] += dis[front.first][front.second] + 1;
                     count[newRow][newCol] ++;
                     q.push({newRow, newCol});
                 }
             }
         }
        
    }
    
    int shortestDistance(vector<vector<int>>& grid) {
       
        vector< vector<int> > dis(grid.size(), vector<int>(grid[0].size(), 0));
        
        vector< vector<int> > count(grid.size(), vector<int>(grid[0].size(), 0));
        
        int build= 0;
        for(int row = 0; row < grid.size(); row ++ ){
            for(int col = 0; col < grid[0].size(); col ++ ){
                if(grid[row][col] == 1){
                     build ++ ;
                     queue< pair<int, int > > q;
                     vector< vector<int> > tempDis(grid.size(), vector<int>(grid[0].size(), 0));
                     
                     q.push({row, col});
                    
                     bfs(grid, tempDis, q, count, dis);
                    
                    
                    // cout << dis[1][2] << endl;
                }
            }
        }
        
        int mn = 1e9;
        
        int newRow = 0, newCol = 0;
        
        for(int row = 0; row < grid.size(); row ++ ){
            for(int col = 0; col < grid[0].size(); col ++ ){
                if(grid[row][col] == 0 && count[row][col] == build ){
                    if( mn > dis[row][col]){
                        newRow = row;
                        newCol = col;
                        mn = dis[row][col];
                    }
                }
            }
        }
        
       int ans = 0;
        
       if (mn == 1e9 || mn == 0) {
           return -1;
       }
        
        for(int row = 0; row < grid.size(); row ++ ){
            for(int col = 0; col < grid[0].size(); col ++ ){
                if(grid[row][col] == 1){
                   ans = min(ans, abs(newRow - row) + abs(newCol - col));
                }
            }
        }
        // cout << dis[3][4]  << endl;
        
    
       return dis[newRow][newCol];
        
    }
};