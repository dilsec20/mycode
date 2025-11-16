#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> v = {1,2,3, 4, 5, 6};

    v.push_back(10); 
    v.pop_back();  //remove last element
    cout<<v.at(2)<<'\n';

    cout<<v.size()<<'\n';

    cout<<((v.empty()) ? "YES" : "NO");
    cout<<'\n';

    //v.clear();

    cout<<v.back()<<'\n';


    //for(int x:v) cout<<x<<" ";
    for(auto it = v.begin(); it != v.end(); it++){
        cout<< *it <<" ";
    }
    cout<<'\n';

    vector<int> v2 = {5 ,6 ,7, 2};
     
    cout<< ((v2>v) ? "YES" : "NO");
    
     

}