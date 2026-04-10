class Solution {
public:
    void traversal(vector<vector<char>> &grid, vector<vector<int>> &visited, int i, int j){
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && !visited[i][j] 
        && grid[i][j] == '1'){
            visited[i][j] =1;
            traversal(grid,visited, i+1,j);
            traversal(grid,visited, i-1,j);
            traversal(grid,visited, i,j+1);
            traversal(grid,visited, i,j-1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>visited(n, vector<int>(m,0));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && visited[i][j] == 0){
                    traversal(grid, visited, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
