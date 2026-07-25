class Solution {
public:
    bool isValid(int n,int k,vector<int> nums,int minlargestsum){
    int number=1,sum=0;
    for (int i = 0; i < n; i++)
    {
        if(nums[i]>minlargestsum){
            return false;
        }
        if(sum+nums[i]<=minlargestsum){
            sum+=nums[i];
        }
        else{
            number++;
            sum=nums[i];
        }
    }
    return number<=k;
}

int splitArray(vector<int>& nums, int k) {
    int n=nums.size();
    int st=*max_element(nums.begin(),nums.begin()+n);
    int end=accumulate(nums.begin(),nums.end(),0);
    int ans=0;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(isValid(n,k,nums,mid)){
            ans=mid;
            end=mid-1;
        }
        else st=mid+1;
    }
    return ans;
}
};