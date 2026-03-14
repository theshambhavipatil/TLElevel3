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
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    set<int> s;
    for (auto& i : a) {
        cin>>i;
        s.insert(i);
    }

    vector<int> b;
    for (auto& i : s) {
        b.push_back(i);
    }
    int n1=b.size();

    map<int,int> mp;
    for (int i=0; i<n; i++) {
        mp[a[i]]++;
    }

    int dance=1;
    int student=0;
    int ans=0;
    for (int left=0,right=0;right<n1;right++) {
        // dance*=mp[b[right]];
        // dance%=MOD;
        dance=mod_mul(dance,mp[b[right]],MOD);
        student++;
        while (student>m ) {
            dance=mod_div(dance,mp[b[left]],MOD);
            // dance/=mp[b[left]];
            // dance%=MOD;
            left++;
            student--;
        }
        if (student==m && b[right]-b[left]<m) {
            ans+=dance;
            ans%=MOD;
        }
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
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}