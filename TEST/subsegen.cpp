#include <bits/stdc++.h>
using namespace std;

int main(){
    
    vector<int> arr = {1,2,3};
    int n = arr.size();

    vector<vector<int>>sub;


    for(int mask= 0; mask<(1<<n); mask++){
        vector<int>subset;
        for(int i = 0; i<n; i++){
            if(mask & (1<<i) )subset.push_back(arr[i]);
        }

        sub.push_back(subset);
    }

    for(auto &s:sub){
        cout<<"{";
        for(int k:s)cout<<k<<" ";
        cout<<"}\n";
    }
    return 0;
}

