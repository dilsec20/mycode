#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> p = {3,2,1};
    do {
        for (int x : p) cout << x << " ";
        cout << "\n";
    } while (prev_permutation(p.begin(), p.end()));

    cout<<'\n';

    vector<int> p2 = {1,2,3};
    do {
        for (int x : p2) cout << x << " ";
        cout << "\n";
    } while (next_permutation(p2.begin(), p2.end()));


    return 0;

}
