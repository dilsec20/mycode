#include <bits/stdc++.h>
using namespace std;

int main() {
    // vector<int> arr = {1,3,-1,-3,5,3,6,7};
    // int k = 3;
    // multiset<int> window;

    // for (int i = 0; i < arr.size(); i++) {
    //     window.insert(arr[i]);

    //     if (i >= k - 1) {
    //         cout << *window.rbegin() << " "; 

           
    //         window.erase(window.find(arr[i - k + 1]));
    //     }
    // }
    // cout << "\n";
    string s = "klno";
    char a = s[0];
    int mask = 0;
    for(char c : s) mask |= (1 << (c-a));
    for(int i=0;i<5;i++)
        if((mask & (1<<i)) == 0) cout << "Missing letter: " << char(a+i) << endl;


    

    return 0;
}
