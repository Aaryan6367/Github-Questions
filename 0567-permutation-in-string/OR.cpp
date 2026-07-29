#include <bits/stdc++.h>
using namespace std;

bool isFreqSame(int freq1[],int freq2[]){
    for (int i = 0; i < 26; i++)
    {
        if(freq1[i]!=freq2[i]){
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    if(s1.length()>s2.length()) return false;
    int freq[26]={0};
    for (int i = 0; i < s1.length(); i++)
    {
        freq[s1[i]-'a']++;
    }
    int freq1[26]={0};
    for (int i = 0; i < s1.length(); i++)
    {
        freq1[s2[i]-'a']++;
    }
    if(isFreqSame(freq,freq1)) return true;
    for (int i = 1; i < s2.length()-s1.length()+1; i++)
    {
        freq1[s2[i-1]-'a']--;
        freq1[s2[i+s1.length()-1]-'a']++;
        if(isFreqSame(freq,freq1)) return true;
    }
    return false;
}
