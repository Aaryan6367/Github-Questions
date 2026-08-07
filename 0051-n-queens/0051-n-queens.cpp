class Solution {
public:
    bool isSafe(int n,vector<vector<char>> &vec,int row,int col){
    for (int k = 0; k < n; k++)
    {
        if(vec[k][col]=='Q'){
            return false;
        }
    }
    
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         // Check if (i,j) lies on either diagonal through (r,c)
    //         if (i - j == row - col || i + j == row + col) {
    //             vec[i][j] = 0;
    //         }
    //     }
    // }
    for (int di = -1; di <= 1; di+=2)
    {
        for (int dj = -1; dj <= 1; dj+=2)
        {
            int ni=row+di;
            int nj=col+dj;
            while(ni>=0 && ni<n && nj>=0 && nj<n){
                if(vec[ni][nj]=='Q'){
                    return false;
                }
                ni+=di;
                nj+=dj;
            }
        }
    }
    return true;
}

void nqueens(int n,int level,vector<vector<string>> &ans,vector<vector<char>> &vec){
    if(level==n){
        vector<string> newvec(n);
        for (int i = 0; i < n; i++)
        {
            string s="";
            for (int j = 0; j < n; j++)
            {
                s+=vec[i][j];
            }
            newvec[i]=s;
        }
        ans.push_back(newvec);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if(isSafe(n,vec,level,i)){
            vec[level][i]='Q';
            nqueens(n,level+1,ans,vec);
            vec[level][i]='.';
        }
        // else if(i==n-1) return;
        // else{
        //     vec[level][i]='.';
        // }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<vector<char>> vec(n, vector<char>(n, '.'));
    nqueens(n,0,ans,vec);
    return ans;
}
};