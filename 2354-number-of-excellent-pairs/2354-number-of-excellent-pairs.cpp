class Solution {
public:

long long countExcellentPairs(vector<int>& vec, int k) {
    set<int> s(vec.begin(), vec.end());
    
    vector<int> countsetbits;
    for (int num : s) {
        countsetbits.push_back(__builtin_popcount(num));
    }
    
    sort(countsetbits.begin(), countsetbits.end());
    
    long long ans = 0;
    int i = 0;
    int j = countsetbits.size() - 1;
    
    while (i < j) {
        if (countsetbits[i] + countsetbits[j] >= k) {
            ans += (j - i);
            j--;
        } else {
            i++;
        }
    }
    
    ans *= 2;
    
    for (int bits : countsetbits) {
        if (bits * 2 >= k) {
            ans++;
        }
    }
    
    return ans;
}
};