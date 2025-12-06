// valid or  not
class Solution {
  public:
    void helper(int row , int col, vector<vector<int>>& maze,vector<string>& ans , string path){
        int n = maze.size() ; 
        if(row<0 || col<0 || row>=n || col>=n||maze[row][col]==0){return  ; }
        else if(row==n-1&&col==n-1){
            ans.push_back(path);
            return ; 
        }
        else{ 
            maze[row][col] = 0 ;
            helper(row+1,col,maze,ans,path+'D') ; 
            helper(row,col-1,maze,ans,path+'L') ;
            helper(row,col+1,maze,ans,path+'R') ;
            helper(row-1,col,maze,ans,path+'U') ;
            maze[row][col]=1 ; 
        }
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size() ;
        vector<string>ans ; 
        string path = "" ; 
        helper(0,0,maze,ans,path) ; 
        return ans ;
        
    }
};
// TO GET THE GRID 
class Solution {
public:
    const int dr[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    const int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    bool solve(int r, int c, int moveCount, vector<vector<int>>& grid, int n) {
        if (moveCount == n * n) return true ; 
        for (int i = 0; i < 8; i++) {
            int next_r = r + dr[i];
            int next_c = c + dc[i];
            if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < n && grid[next_r][next_c] == -1) {
                grid[next_r][next_c] = moveCount; 
                if (solve(next_r, next_c, moveCount + 1, grid, n)) return true;
                grid[next_r][next_c] = -1;
            }
        }
        return false;
    }

    vector<vector<int>> knightTour(int n) {
        vector<vector<int>> grid(n, vector<int>(n, -1));
        grid[0][0] = 0;
        if (solve(0, 0, 1, grid, n)) {
            return grid;
        }
        return {};
    }
};
