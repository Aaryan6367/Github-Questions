class Solution {
public:
    bool searchinarow(vector<vector<int>>& matrix, int target,int row){
    int st=0;
    int end=matrix[0].size()-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(matrix[row][mid]==target){
            return true;
        }
        if(target<matrix[row][mid]){
            end=mid-1;
        }
        else st=mid+1;
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {//O(log(mn))
    int m=matrix.size();
    int n=matrix[0].size();
    int strow=0;
    int endrow=m-1;
    while(strow<=endrow){
        int midrow=strow+(endrow-strow)/2;
        if(target>=matrix[midrow][0] && target<=matrix[midrow][n-1]){
            return searchinarow(matrix,target,midrow);
        }
        if(target>matrix[midrow][n-1]){
            strow=midrow+1;
        }
        else endrow=midrow-1;
    }
    return false;
}
};