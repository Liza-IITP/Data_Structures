def isSafe(N,grid,i,j,k):
    for x in range(N):
        if grid[x][j] == k:
            return False
    for y in range(N):
        if grid[i][y] == k:
            return False
    startRow = i - i%(N//3)
    startCol = j - j%(N//3)
    for x in range(startRow, startRow + N//3):
        for y in range(startCol, startCol + N//3):
            if grid[x][y] == k:
                return False
    return True
def solveSudoku(N,grid) :
    for i in range(N):
        for j in range(N):
            if grid[i][j] == 0:
                for k in range(1, N+1):
                    if isSafe(N, grid, i, j, k):
                        grid[i][j] = k                        
                        if solveSudoku(N, grid):                           
                            return True
                        grid[i][j] = 0
                return False
    return True
def printGrid(N,grid):
    for i in range(N):
        for j in range(N):
            print(grid[i][j], end = " ")
        print()
grid = [[2,0,3],[1,0,0],[0,0,1]]
N = 3
print("Before solving")
printGrid(N, grid)
solveSudoku(N, grid)
print("After solving")
printGrid(N, grid)
if solveSudoku(N, grid):
    printGrid(N, grid)
else:
    print("No solution exists")
N = 9
grid = [
    [5, 3, 0, 0, 7, 0, 0, 0, 0],
    [6, 0, 0, 1, 9, 5, 0, 0, 0],
    [0, 9, 8, 0, 0, 0, 0, 6, 0],
    [8, 0, 0, 0, 6, 0, 0, 0, 3],
    [4, 0, 0, 8, 0, 3, 0, 0, 1],
    [7, 0, 0, 0, 2, 0, 0, 0, 6],
    [0, 6, 0, 0, 0, 0, 2, 8, 0],
    [0, 0, 0, 4, 1, 9, 0, 0, 5],
    [0, 0, 0, 0, 8, 0, 0, 7, 9]
]

if solveSudoku(N, grid):
    printGrid(N, grid)
else:
    print("No solution exists")
