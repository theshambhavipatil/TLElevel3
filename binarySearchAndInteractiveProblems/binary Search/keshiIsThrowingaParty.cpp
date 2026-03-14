
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

bool possible(int mid,vector<pair<int,int>> &v) {
    ll count=0;
    for (int i=0;i<v.size();i++) {
        int val1=v[i].first;
        int val2=v[i].second;
        if (count+val1+1>=mid && count<=val2) {
            count++;
        }
    }
    // cout<<count<<endl;
    if (count>=mid) {
        return true;
    }
    return false;

}

void solve() {
    // Solution logic here
    ll n;
    cin >> n;
    vector<pair<int,int> > v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i].first;
        cin >> v[i].second;
    }

    int ans = INT64_MIN;
    int start = 0, end = n;
    while (start <= end) {
        ll mid = start + (end - start) / 2;
        // cout<<"start "<<start<<" mid "<<mid<<" end "<<end<<endl;
        if (possible(mid,v)) {
            ans=max(ans, mid);
            start=mid+1;
        }
        else {
            end=mid-1;
        }
    }
    cout << ans << endl;
}

signed main() {
    FAST_IO;


    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
