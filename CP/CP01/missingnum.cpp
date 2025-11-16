#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long x = 0;
    for(int i = 0; i < n-1; i++){
        int num;
        cin >> num;
        x ^= (i+1);  
        x ^= num;   
    }
    x ^= n; 

    cout << x << endl; 
}
