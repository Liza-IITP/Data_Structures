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
