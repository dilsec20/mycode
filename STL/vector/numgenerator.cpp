#include <bits/stdc++.h>
using namespace std;

int main(){

   int n,k; 
   cin>>n>>k;

   vector<int> num(n);

   iota(num.begin(), num.end(), k);

   for(int x:num)cout<<x<<" ";


    return 0;

}
