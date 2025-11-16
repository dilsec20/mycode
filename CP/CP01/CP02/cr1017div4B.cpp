#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, m, l, r;
        cin >> n >> m >> l >> r;

        int diff = n - m;
        int l1,r1;
        if(l==0){
            l1 = l;
            r1 = r -diff;
        }else{
            int leftShrink = (diff + 1) / 2;  
            int rightShrink = diff - leftShrink;

            l1 = l + leftShrink;
            r1 = r - rightShrink;
        } 

        cout << l1 << " " << r1 << "\n";
    }
}
