
#include <bits/stdc++.h>
#define int long long
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
    int n;
    cin >> n;
    vector<ll> pre(n,0);
    for (int i = n-1; i >=1 ; i--) {
        cout<<"? "<<1<<" "<<i+1<<endl;
        cin>>pre[i];
    }
    cout<<"? "<<2<<" "<<n<<endl;
    int val;
    cin>>val;
    pre[0]=pre[n-1]-val;

    // cout<<"pre[0]"<<pre[0]<<endl;

    cout<<"! ";
    vector<ll> v(n);
    v[0]=pre[0];
    for (int i = 1; i <n ; i++) {
        v[i]=pre[i]-pre[i-1];
    }

    for (int i=0; i < n; i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

signed main() {
    FAST_IO;
    
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     freopen("Error.txt", "w", stderr);
// #endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}