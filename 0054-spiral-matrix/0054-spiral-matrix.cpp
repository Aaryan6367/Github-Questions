class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();
    int scol=0,ecol=n-1,srow=0,erow=m-1;
    vector<int> ans;
    while(srow<=erow && scol<=ecol){
        //Upper
        for (int i = scol; i <= ecol; i++)
        {
            ans.push_back(matrix[srow][i]);
        }

        //Right
        for (int i = srow+1; i <= erow; i++)
        {
            ans.push_back(matrix[i][ecol]);
        }

        //Bottom
        for (int i = ecol-1; i >= scol; i--)
        {
            if(erow==srow) break;
            ans.push_back(matrix[erow][i]);
        }

        //Left
        for (int i = erow-1; i > srow; i--)
        {
            if(ecol==scol) break;
            ans.push_back(matrix[i][scol]);
        }
        srow++,erow--,scol++,ecol--;
    }
    return ans;
}
};