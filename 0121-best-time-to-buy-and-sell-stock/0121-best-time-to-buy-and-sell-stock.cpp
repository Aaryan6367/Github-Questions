class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int bestBuy=INT_MAX;
    int ans=0;
    for (int i = 0; i < prices.size(); i++)
    {
        if(prices[i]<bestBuy){
            bestBuy=prices[i];
            continue;
        }
        ans=max(ans,prices[i]-bestBuy);
    }
    return ans;
}
};