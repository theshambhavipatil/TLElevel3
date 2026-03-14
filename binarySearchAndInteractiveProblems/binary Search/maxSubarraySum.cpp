
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


// when there is no >= d constraint
ll maxSubarraySum(vector<ll> v, ll n) {
    vector<ll> pre(v.size());
    pre[0] = v[0];
    for (ll i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + v[i];
    }

    ll ans = 0;
    ll minSubArr = 0;
    for (ll i = 0; i < n; i++) {
        ll bestPossibleSubarrSum = pre[i] - minSubArr;
        minSubArr = min(minSubArr, pre[i]);
        ans = max(ans, bestPossibleSubarrSum);
    }
    return ans;
}

void solve() {
    // Solution logic here
}

signed main() {
    FAST_IO;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
