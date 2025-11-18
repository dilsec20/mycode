#include <bits/stdc++.h>
using namespace std;

                              /* DILIP KUMAR */

// ------------------------ TYPEDEFS ------------------------
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

// ------------------------ MACROS ------------------------
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define ff first
#define ss second
#define f(i,n) for(int i=0;i<(n);++i)
#define F0R(i,a,b) for(int i=(a);i<=(b);++i)
#define FOREACH(x,v) for(auto &x : v)
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)

// ------------------------ CONSTANTS ------------------------
const ll MOD = 1e9+7;
const ll INF = 1e18;
const int MAXS = 400000;
//static int spf[MAXS+1];
const int INF_INT = 1e9;


// ------------------------ MATH FUNCTIONS ------------------------
ll addmod(ll a,ll b){ return ( (a%MOD + b%MOD) % MOD + MOD )%MOD; }
ll submod(ll a,ll b){ return ( (a%MOD - b%MOD) % MOD + MOD )%MOD; }
ll mulmod(ll a,ll b){ return ((a%MOD)*(b%MOD))%MOD; }
ll modpow(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=mulmod(res,a);
        a=mulmod(a,a);
        b>>=1;
    }
    return res;
}
ll modinv(ll a){ return modpow(a,MOD-2); }
ll gcdll(ll a,ll b){ return b?gcdll(b,a%b):a; }
ll lcmll(ll a,ll b){ return (a/gcdll(a,b))*b; }

// ------------------------ STL SHORTCUTS ------------------------
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define el '\n'
#define sortall(b) sort(all(b))
#define uniq(x) x.erase(unique(all(x)), x.end())


                    /*  JAY SHREE RAM  */

// ------------------------ MAIN ------------------------


void solve() {
    string s;
    cin >> s;

    for(int j = s.size()-1; j>=0; j--){
        s += s[j];
    }

    cout << s << endl;
    
}

int main() {
    fast_io;
    // int t;
    // cin>>t;
    // while(t--)
        solve();
    return 0;
}
