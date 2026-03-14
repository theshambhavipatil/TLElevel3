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


vector<int> getAverages(vector<int>& nums, int k) {
    vector<int> pre(nums.size());
    pre[0] = nums[0];
    for (int i=1;i<pre.size();i++) {
        pre[i] = pre[i-1] + nums[i];
    }
    int n=nums.size();
    vector<int> ans(n,-1);
    for (int i=0;i<n;i++) {
        if (i>k-1 && i<n-k) {
            // cout<<i<<" ";
            // cout<<pre[i+k]-(i-k-1>=0)?pre[i-k-1]:0;
            // cout<<endl;

            ans[i] = floor((pre[i+k]-(i-k-1>=0?pre[i-k-1]:0))/((2*k)+1) );

        }
    }

    return ans;
}

void solve() {
    // Solution logic here
    vector<int> nums={7,4,3,9,1,8,5,2,6};
    int k=3;
    vector<int> ans=getAverages(nums,k);
    for (int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main() {
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