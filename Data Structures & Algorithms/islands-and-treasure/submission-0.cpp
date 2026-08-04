class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;

        if(rows == 0) return;

        for(int i=0; i<rows; i++){
            for (int j=0; j<cols; j++){
                if(grid[i][j] ==0){
                    q.push({i,j});
                }
            }
        }
        
        // 2. Directions for 4-way movement (up, down, left, right)

        vector<pair<int,int>> dirs = {{0,1},{0,-1},{-1,0},{1,0}};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(auto &dir:dirs){
                int nrow = row + dir.first;
                int ncol = col + dir.second;

                if(nrow>=0 && nrow<rows && ncol>=0 && ncol<cols && grid[nrow][ncol] == 2147483647){
                    grid[nrow][ncol] = grid[row][col] + 1; 
                    q.push({nrow,ncol});
                }
            }

        }
        
    }
};
