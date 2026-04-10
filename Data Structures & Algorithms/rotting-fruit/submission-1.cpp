class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time =0;
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>>q;
        int fresh=0;
        int rotten =0;

        vector<vector<int>>directions = {
            {-1,0},
            {1,0},
            {0,-1},
            {0,1},
        };
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    rotten++;
                    fresh++;
                    q.push({i,j});
                }
                else if(grid[i][j] ==1)fresh++;
            }
        }
        if (fresh == rotten) return 0;

        while(!q.empty()){
            
            
            int sz = q.size();
            for(int k=0 ; k<sz ;k++){
                auto it = q.front();
                q.pop();
                
                for(auto dir : directions){
                    int i =it.first + dir[0];
                    int j = it.second + dir[1];
                    if(i<0 || i>=m || j<0 || j>=n || grid[i][j] != 1){
                        continue;
                    }
                    grid[i][j] =2;
                    rotten++;
                    q.push({i,j});

                }
            }
            time++;

        }
        if(rotten != fresh)return -1;
        return time-1;
    }
};
