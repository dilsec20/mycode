#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    vector<int>pro;
    int maxx=0;
    for(int i= 0; i<n; i++) cin>>arr[i];
    int maxxx = INT_MIN;

    int minn = *min_element(arr.begin(), arr.end());

    for(int i =0;i<n;i++){
        if(minn == arr[i]){
            pro.push_back(i);
        }
    }
    for(int i = pro[0]; i<n;i++){
        if(arr[i]>maxxx){
            maxxx = arr[i];
        }
    }

    
    cout<<max(maxxx-minn,0);
    return 0;

}