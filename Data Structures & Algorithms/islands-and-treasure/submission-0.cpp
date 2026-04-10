class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>>directions = {
            {0,-1},
            {0,1},
            {-1,0},
            {1,0},
        };
        while(!q.empty()){
            auto it = q.front();
            
            q.pop();
            

           
            for(auto dir : directions){
                int r = it.first + dir[0];
                int c = it.second + dir[1]; 
                 if(r<0 || r>=m || c<0 || c>=n || grid[r][c] !=INT_MAX){
                continue;
                }

                grid[r][c] = 1+ grid[it.first][it.second];
                q.push({r,c});
            }
        }
    }
};
