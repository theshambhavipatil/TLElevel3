#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;


typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

template<class T>
using ordered_set = tree<
    T,
    null_type,
    less<T>, // comparison (can use less_equal<T> for multiset-like)
    rb_tree_tag,
    tree_order_statistics_node_update>;

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
    cin>>n;
    vector<char> v(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
    }
    set<int> s;
    for(int i = 0; i < n; i++) {
        s.insert(v[i]);
    }
    int val=s.size();
    int l=0, r=0;
    map<int,int> mp;
    int ans=INT_MAX;
    while(r<n) {
        mp[v[r]]++;
        // cout<<v[r]<<" "<<mp[v[r]]<<endl;
        while (l<=r && mp.size()==val) {
            ans=min(r-l+1,ans);
            // cout<<l<<" "<<r<<endl;
            mp[v[l]]--;
            if (mp[v[l]]==0) {
                // cout<<"yes"<<endl;
                // cout<<v[l]<<endl;
                mp.erase(v[l]);
                l++;
                break;
            }
            l++;
        }
        r++;
    }
    cout<<ans<<endl;

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