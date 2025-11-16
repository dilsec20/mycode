#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        
        int totalA = accumulate(a.begin(), a.end(), 0);
        int totalB = accumulate(b.begin(), b.end(), 0);

        

        if(totalB == 0){
            cout<<n<<"\n";
        }
        if(totalA>totalB){
            cout<<(totalA-totalB)*n<<"\n";
        }
        
        
    }
    return 0;
}
