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
    int n,k;
    cin>>n>>k;
    vector<int> v1(n);
    for(int i=0;i<n;i++) {
        cin>>v1[i];
    }
    vector<int> v2(n);
    for(int i=0;i<n;i++) {
        cin>>v2[i];
    }

    int ans=0;
    int num=0;
    int sum=0;
    for (int l=0,r=0;r<n;r++) {

        if (r<n-1)
        {
            if (v2[r]%v2[r+1]!=0) {
                l=r+1;
                r=r+1;
            }
        }

            sum+=v2[r];
            num+=v1[r];
            while ((num>k) && l<=r) {
                // cout<<"ahead "<<v2[l]%v2[r]<<endl;;
                num-=v1[l];
                sum-=v2[l];
                l++;
            }
            // cout<<num<<" "<<k<<endl;
            if (num<=k   && l<=r && l>=0) {
                // cout<<"left "<<l<<" "<<r<<" "<<num<<endl;
                ans=max(ans,r-l+1);
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