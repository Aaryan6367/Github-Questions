class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> save;
    vector<int> vec;
    for (int i = 0; i < nums.size(); i++)
    {   
        int first=nums[i];
        int element=target-first;
        if(save.find(element)!=save.end()){
            vec.push_back(i);
            vec.push_back(save[element]);
            break;
        }
        save[first]=i;
    }
    return vec;
}
};