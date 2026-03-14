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
    string s;
    cin>>s;
    int n=s.length();

    vector<char> v1;
    vector<char> v2;

    for(int i=0;i<n;i++) {
        if ((s[i]-'0')%2==0) {
            v1.push_back(s[i]);
        }
        else {
            v2.push_back(s[i]);
        }
    }


    int n1=v1.size();
    int n2=v2.size();

    // for(int i=0;i<n1;i++) {
    //     cout<<v1[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<n2;i++) {
    //     cout<<v2[i]<<" ";
    // }

    int num1=0,num2=0;

    string s2;

    while(num1<n1 && num2<n2) {
        if (v1[num1]-'0'<v2[num2]-'0') {
            s2.push_back(v1[num1++]);
        }
        else {
            s2.push_back(v2[num2++]);
        }
    }
    while(num1<n1) {
        s2.push_back(v1[num1++]);
    }
    while(num2<n2) {
        s2.push_back(v2[num2++]);
    }

    // reverse(s2.begin(),s2.end());
    cout<<s2<<endl;
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