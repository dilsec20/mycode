#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

// bool checks(string s){
//     if(s=="X++" || s== "++X") {
//         return true;
//     }
//     else{
//         return false;
//     }
    
// }

int main(){
    int  n ;
    cin>>n;
    int x =0;
    for(int i = 0; i<n;i++){
        string s;
        cin>>s;
        if(s=="++X" || s=="X++") {
             x++;
        }else{
            x--;
        }

        // if(checks(s)){
        //     x++;
        // }
        // else{
        //     x--;
        // }

        
    }
    cout<<x<<"\n";
    return 0;
    
}