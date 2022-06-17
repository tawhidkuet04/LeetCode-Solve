struct Node{
    int x;
    int y;
    int dis;
    
    Node(int x, int y, int dis){
        this->x = x;
        this->y = y;
        this->dis = dis;
    }
};

class Solution {
public:
    
    bool isValid(int newRow, int newCol, vector<vector<int>>& grid,  vector< vector<int> > &vis){
        if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == 0 && vis[newRow][newCol] == 0){
            return true;
        }
        
        return false;
    }
    int bfs(vector<vector<int>>& grid){
        queue< Node> q;
        
        if(grid[0][0] == 0){
             q.push(Node(0,0,1));
        }else{
            return -1;
        }
       
        
        int rowSize = grid.size();
        int colSize = grid[0].size();
        
        vector< vector<int> > vis(rowSize, vector<int>(colSize, 0));
        
        vis[0][0] = 1;
        
        int fx[8] = {+1,-1,0,0    ,+1, - 1, -1, +1};
        int fy[8] = {0, 0 , +1, -1,+1, + 1, -1, -1};
        
        while(!q.empty()){
            Node front = q.front();
            
            q.pop();
            
            if(front.x == rowSize - 1 && front.y == colSize - 1){
                return front.dis;
            }
            
            for(int index = 0; index < 8; index ++ ){
                int newRow = front.x + fx[index];
                int newCol = front.y + fy[index];
                 
                if(isValid(newRow, newCol, grid, vis)){
                    cout << newRow << " " << newCol << endl;
                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol, front.dis + 1});
                }
            }
        }
        
        return -1;
    
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};