class Solution {
public:
    bool isValid(vector<vector<char>>& board,int row,int col,char val){
    for (int i = 0; i < 9; i++)
    {
        if(board[row][i]==val) return false;
        if(board[i][col]==val) return false;
    }
    int bx=col/3;
    int by=row/3;
    for (int i = by*3; i < by*3+3; i++)
    {
        for (int j = bx*3; j < bx*3+3; j++)
        {
            if(board[i][j]==val){
                return false;
            }
        }
    }
    return true;
}

bool sudoku(vector<vector<char>>& board,int row,int col){
    if(row==9){
        return true;
    }
    int newrow=row;
    int newcol=col+1;
    if(newcol==9){
        newrow+=1;
        newcol=0;
    }

    if(board[row][col]!='.'){
        return sudoku(board,newrow,newcol);
    }
    for (int i = 1; i <= 9; i++)
    {
        char val='0'+i;
        if(isValid(board,row,col,val)){
            board[row][col]=val;
            if(sudoku(board,newrow, newcol)){
                return true;
            }
            board[row][col]='.';
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    sudoku(board,0,0);
}
};