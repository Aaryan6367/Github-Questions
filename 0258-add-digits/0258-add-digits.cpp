class Solution {
public:
    int addDigits(int num) {
        if(num==0){
            return 0;
        }
        int k=num%9;
        if(k==0){
            return 9;
        }
        else return k;
    }
};