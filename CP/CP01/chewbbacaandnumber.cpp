#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){

    ll n;
    cin>>n;

    string s = to_string(n);
     
    for(int i = 0; i<s.size(); i++){
        if (i == 0 && s[i] == '9') continue;

        if(s[i] > '4' )
        s[i] = '0' + ('9' - s[i]);


    }
  
    ll newNum = stoll(s);
    cout << newNum << endl;

    return 0;

}