#include <bits/stdc++.h>

using namespace std;

int main(){

    deque<int> dq = {1, 2, 3};

    dq.push_back(4);
    cout<<dq.front()<<'\n';

    cout<<dq.size()<<'\n'; 

    for(auto d:dq)cout<<d<<" ";

    dq.clear();
    

    return 0;

}//