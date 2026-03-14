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
    vector<int> nums(n);
    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }
    vector<int> val(n,0);
    for(int i=1; i<n-1; i++) {
        if (nums[i]>nums[i-1] && nums[i]>nums[i+1]) {
            val[i]=1;
        }
    }
    vector<int> temp=val;
    for(int i=1; i<n; i++) {
        val[i]=val[i-1]+val[i];
    }

    // for (int i=0;i<n;i++) {
    //     cout<<val[i]<<" ";
    // }
    // cout<<endl;

    int maxVal=INT_MIN;
    int idx=-1;

    int val2=temp[0];
    int val3=temp[k-1];
    int count=0;
    if (val2==1) {
        count++;
    }
    if (val3==1) {
        count++;
    }
    maxVal=max(maxVal,val[k-1]-count);
    idx=1;
    // cout<<maxVal<<" "<<idx<<endl;

    for(int i=k; i<n; i++) {
        count=0;
        if (temp[i]==1) {
            count++;
        }
        if (temp[i-k+1]==1) {
            count++;
        }
        if (val[i]-val[i-k]-count>maxVal) {
            maxVal=val[i]-val[i-k]-count;
            idx=i-k+2;
        }
        // cout<<maxVal<<" "<<idx<<endl;
    }

    cout<<maxVal+1<<" "<<idx<<endl;
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