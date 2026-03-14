//
// Created by Admin on 25-01-2026.
//


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
    string s,t;
    cin>>s>>t;

    ll len=s.length();
    ll len1=t.length();

    map<int,int> mp;
    for (ll i=0;i<len;i++) {
        mp[s[i]]++;
    }
    map<int,int> temp=mp;
    map<int,int> mp1;
    for (ll i=0;i<len1;i++) {
        mp1[t[i]]++;
    }
    ll ans=INT_MIN;

    for (int left=0,right=0;right<len;right++) {
        mp[s[right]]--;
        while (mp[s[right]]<mp1[s[right]]&& right>=left) {
            cout<<"yes"<<" "<<right<<endl;
            mp[s[left]]++;
            left++;
        }

        if (mp[s[right]]>=mp1[s[right]] && right>=left) {
            cout<<(right-left+1)<<" "<<right<<" "<<left<<endl;
            ans=max(ans,(ll)(right-left+1));
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
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}