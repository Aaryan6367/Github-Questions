class Solution {
public:
    int maxArea(vector<int> &height){//O(n)
    int maxVol=0;
    int lp=0,rp=height.size()-1;
    while(lp<rp){
        int width=rp-lp;
        int ht=min(height[lp],height[rp]);
        int currVol=ht*width;
        maxVol=max(maxVol,currVol);

        height[lp]<height[rp]?lp++:rp--;
    }
    return maxVol;
}
};