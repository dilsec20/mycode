#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>> t;
    while(t--){
        int n;
        n =4;
        int arr[n];
        
        for(int i =0; i<4; i++){
            cin>>arr[i];   
        }
        int a = arr[0], b=arr[1], d=arr[2], e=arr[3];
        
        int k = 101; 
        for (int c = -100; c <= 100; c++) {
        if (a + b == c || b + c == d || c + d == e) {
            k = c;
            break;  
            }
        }
        int t;

        vector<int > res(arr, arr+n);
        res.insert(res.begin() + 2 , k);

        for(int i = 0; i<5; i++){
            int x,y,z;

            if(res[0] + res[1] == res[2])  x = 1; else x = 0;
            if(res[1] + res[2] == res[3]) y = 1; else  y = 0;
            if(res[2] + res[3] == res[4]) z = 1; else  z = 0;

            t = x+y+z;  
        }
        cout<<t<<"\n";  
    }
    return 0;   
}