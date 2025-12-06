class Solution {
public:
    bool helper(int row , int col , int current , vector<vector<int>>&grid){
        int n = grid.size() ; 
        if(row<0||col<0||row>=n||col>=n||grid[row][col]!=current){return false; }
        if(current==n*n-1&& grid[row][col]==n*n-1){return true ; }
        bool a1 = helper(row+2,col-1,current+1,grid) ; 
        bool a2 = helper(row+2,col+1,current+1,grid) ;
        bool a3 = helper(row-2,col-1,current+1,grid) ;
        bool a4 = helper(row-2,col+1,current+1,grid) ;
        bool a5 = helper(row-1,col+2,current+1,grid) ;
        bool a6 = helper(row-1,col-2,current+1,grid) ;
        bool a7 = helper(row+1,col-2,current+1,grid) ;
        bool a8 = helper(row+1,col+2,current+1,grid) ;
        return (a1||a2||a3||a4||a5||a6||a7||a8) ; 
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]!=0){return false ; }
        return helper(0,0,0,grid) ;
    }
};
