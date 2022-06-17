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
    
    bool isValid(int newRow, int newCol, vector<vector<int>>& grid){
        if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() && grid[newRow][newCol] == 0){
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
                 
                if(isValid(newRow, newCol, grid)){
                    cout << newRow << " " << newCol << endl;
                    grid[newRow][newCol] = 2;
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