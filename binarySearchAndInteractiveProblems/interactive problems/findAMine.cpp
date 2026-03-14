
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

const ll MOD = 1e9 + 7;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

ll expo(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
ll mod_mul(ll a, ll b, ll m) { return (a % m * b % m) % m; }
ll mod_sub(ll a, ll b, ll m) { return ((a - b) % m + m) % m; }
ll mod_div(ll a, ll b, ll m) { return mod_mul(a, mminvprime(b, m), m); }
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }

void solve() {
    // Solution logic here
    int n,m;
    cin>>n>>m;

    cout<<"? "<<1<<" "<<1<<endl;
    int val;
    cin>>val;
    if(val==0){
      cout<<"! "<<1<<" "<<1<<endl;
      return;
    }
    int x1=min(n,1+val);
    int y1=val-x1+2;

    cout<<"? "<<x1<<" "<<y1<<endl;
    int val2;cin>>val2;

    int y2=min(m,1+val);
    int x2=val-y2+2;

    cout<<"? "<<x2<<" "<<y2<<endl;
    int val3;cin>>val3;

    if (val2%2!=0) {
        cout<<"! "<<x2+(val3/2)<<" "<<y2-(val3/2)<<endl;

    }
    else {
        cout<<"? "<<x1-(val2/2)<<" "<<y1+(val2/2)<<endl;
        int val4;cin>>val4;
        if (val4==0) {
            cout<<"! "<<x1-(val2/2)<<" "<<y1+(val2/2)<<endl;
        }
        else {
            cout<<"! "<<x2+(val3/2)<<" "<<y2-(val3/2)<<endl;
        }
    }

}

signed main() {
    FAST_IO;
    
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     freopen("Error.txt", "w", stderr);
// #endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}