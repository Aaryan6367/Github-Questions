class Solution {
public:
    long long countExcellentPairs(vector<int>& vec, int k) {
    set<int> s;
    for (int i = 0; i < vec.size(); i++)
    {
        s.insert(vec[i]);
    }
    vector<int> nums;
    for (auto i = s.begin(); i != s.end(); i++)
    {
        nums.push_back(*i);
    }
    vector<int> countsetbits(nums.size(),0);
    for (int i = 0; i < nums.size(); i++)
    {
        countsetbits[i]=__builtin_popcount(nums[i]);
    }
    sort(countsetbits.begin(),countsetbits.end());
    int i=0;
    long long ans=0;
    int j=countsetbits.size()-1;
    while(i<j){
        while(countsetbits[i]+countsetbits[j]<k && i<j){
            i++;
            if(i==countsetbits.size()){
                break;
            }
        }
        if(i<j){
            long long t=j-i;
            ans+=t;
            j--;
        }
    }
    ans*=2;
    int p=0;
    while(k>countsetbits[p]*2){
        p++;
        if(p==countsetbits.size()){
            break;
        }
    }
    ans+=(countsetbits.size()-p);
    return ans;
}
};