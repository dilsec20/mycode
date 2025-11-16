#include <bits/stdc++.h>
using namespace std;
int main(){

    int n ,k;
    cin>>n>>k;

    vector<pair<int,int>>arr(n);
    int sum =0;
    vector<int>chosen;

    for(int  i= 0; i<n; i++) {
        cin>>arr[i].first; 
        arr[i].second = i+1;
    }
    sort(arr.begin(), arr.end());

    
    for (int i = 0; i < n; i++) {
        if (sum + arr[i].first <= k) {
            sum += arr[i].first;
            chosen.push_back(arr[i].second);
        } else {
            break; 
        }
    }

    cout<<chosen.size()<<"\n";

    for(int i = 0; i<chosen.size(); i++){
        cout<<chosen[i]<<" ";
    }
    return 0;

}