class Solution {
public:
    bool isValid(int n,int m,vector<int> position,int minAllowed){
    int ball=1;
    int pos=position[0];
    for (int i = 0; i < n; i++)
    {
        if(position[i]-pos>=minAllowed){
            ball++;
            pos=position[i];
        }
        if(ball==m){
            return true;
        }
    }
    return false;
}

int maxDistance(vector<int>& position, int m) {
    int n=position.size();
    sort(position.begin(),position.end());
    int st=1;
    int end=position.back()-position.front();
    int ans=0;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(isValid(n,m,position,mid)){
            ans=mid;
            st=mid+1;
        }
        else end=mid-1;
    }
    return ans;
}
};