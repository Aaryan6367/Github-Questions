class Solution {
public:
    bool isAlphaNum(char c){
    if(c>='0' && c<='9' || tolower(c)>='a' && tolower(c)<='z') return true;
    else return false;
}

bool isPalindrome(string s) {
    int n=s.size();
    int st=0,end=n-1;
    while(st<end){
        if(!isAlphaNum(s[st])){
            st++;
            continue;
        }
        if(!isAlphaNum(s[end])){
            end--;
            continue;
        }
        if(tolower(s[st])!=tolower(s[end])) return false;
        st++,end--;
    }
return true;
}
};