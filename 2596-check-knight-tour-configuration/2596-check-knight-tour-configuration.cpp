class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
    if(grid[0][0]!=0) return false;
    int n = grid.size();
    unordered_map<int, pair<int,int>> pos;

    // Step 1: Store positions of each number in hash table
    for(int r=0; r<n; r++){
        for(int c=0; c<n; c++){
            pos[grid[r][c]] = {r,c};
        }
    }

    // Step 2: Start from 0 and check knight moves
    for(int val=0; val<n*n-1; val++){
        auto [r1,c1] = pos[val];
        auto [r2,c2] = pos[val+1];

        int dr = abs(r1-r2);
        int dc = abs(c1-c2);

        // Knight move condition: Δr×Δc = 2 and Δr+Δc = 3
        if(dr*dc != 2 || dr+dc != 3){
            return false;
        }
    }

    return true;
}
};