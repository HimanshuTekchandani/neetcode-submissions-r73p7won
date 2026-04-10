class Solution {
public:
    void traversal(vector<vector<int>>&grid, vector<vector<int>>&visited, int i, int j,
    int &area){
        if(i>=0 &&i<grid.size()&&j>=0 && j<grid[0].size() && grid[i][j]==1 &&
        !visited[i][j]){
            visited[i][j] =1;
            area++;
            traversal(grid,visited,i+1,j,area);
            traversal(grid,visited,i-1,j,area);
            traversal(grid,visited,i,j+1,area);
            traversal(grid,visited,i,j-1,area);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>visited(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int area =0;
                if(grid[i][j] ==1 && visited[i][j] == 0){
                    traversal(grid,visited,i,j,area);
                }
                ans= max(ans,area);
            }
        }
        return ans;
    }
};
