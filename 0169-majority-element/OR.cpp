int majorityElement(vector<int> vec){
    int ele=INT_MIN;
    int count=1;
    for (int i = 0; i < vec.size(); i++)
    {
        if(vec[i]==ele){
            count++;
            continue;
        }
        count--;
        if(count==0){
            ele=vec[i];
            count=1;
            continue;
        }
    }
    return ele;
};
