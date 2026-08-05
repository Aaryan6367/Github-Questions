class Solution {
public:
    int findDuplicate(vector<int>& nums) {//TC-O(n) and SC-O(1), here we used the concept of linked list. We also used the concept of slow fast approach.
    int slow=nums[0];
    int fast=nums[0];
    do{
        slow=nums[slow];
        fast=nums[nums[fast]];
    }
    while(slow!=fast);
    slow=nums[0];
    while(slow!=fast){
        slow=nums[slow];
        fast=nums[fast];
    }
    return slow;
}

};