
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


bool possible(vector<pair<int, int>> v,double time) {
    pair<double,double> p = {-1e18,1e18};
    for (auto x : v) {
        double val1=x.first-(x.second*time);
        double val2=x.first+(x.second*time);
        pair<double,double> p1={val1,val2};
        p.first=max(p1.first,p.first);
        p.second=min(p1.second,p.second);
        if (p.first>p.second) return false;
    }
    return true;
}


void solve() {
    // Solution logic here
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i].first;
      cin >> v[i].second;
    }

    double start=0;
    double end=1e9;
    for (int i=0; i<60 ;i++) {
        double mid=start+(end-start)/2;
        if (possible(v,mid)) {
            end=mid;

        }
        else {
            start=mid;
        }
    }

// fixed used so that we dont get scientific notation  like 1e-5
    cout<<setprecision(7)<<fixed<<end<<endl;

}

signed main() {
    FAST_IO;
    

    int t = 1;

    while (t--) {
        solve();
    }
    
    return 0;
}