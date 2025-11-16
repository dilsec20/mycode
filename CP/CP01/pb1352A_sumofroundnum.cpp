#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<int>values; 
    
        if(n/1000 != 0 ) values.push_back((n/1000)*1000);
        if((n % 1000) / 100 != 0) values.push_back(((n % 1000) / 100) * 100);
        if((n % 100) / 10 != 0) values.push_back(((n % 100) / 10) * 10);
        if(n%10 !=0)values.push_back(n % 10);
    
        cout << values.size() << "\n";
        for (int i = 0; i < values.size(); i++) {
            cout << values[i];
            if (i != values.size() - 1) cout << " ";
        }
        cout << "\n";
           
    }
    return 0;
    
} 