#include<bits/stdc++.h>
using namespace std;
int main(){

    string n;
    cin>>n;
    unordered_map<char,int>freq;
    

    
    int maxfreq =0;
    for (char c : n) {
        freq[c]++;
    
        maxfreq = max(maxfreq, freq[c]);

    }
    cout<<maxfreq<<"\n";
    return 0;
    
    

}