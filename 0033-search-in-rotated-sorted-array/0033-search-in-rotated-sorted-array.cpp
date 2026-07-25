class Solution {
public:
    int search(vector<int>& arr, int tar){
    int st=0;
    int end=arr.size()-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(tar==arr[mid]) return mid;
        if(arr[st]<=arr[mid]){ //Left sorted
            if(arr[st]<=tar && arr[mid]>=tar){
                end=mid-1;
            }
            else st=mid+1;
        }
        else{//Right sorted
            if(arr[mid]<=tar && tar<=arr[end]){
                st=mid+1;
            } 
            else end=mid-1;
        }
    }
    return -1;
}

};