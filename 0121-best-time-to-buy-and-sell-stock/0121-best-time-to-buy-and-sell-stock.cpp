class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int bb=INT_MAX;
    int ans=0;
    for (int i = 0; i < prices.size(); i++)
    {
        if(prices[i]<bb){
            bb=prices[i];
            continue;
        }
        ans=max(ans,prices[i]-bb);
    }
    return ans;
}
};