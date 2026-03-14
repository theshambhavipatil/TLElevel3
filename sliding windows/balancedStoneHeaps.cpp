#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
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

bool possible(vector<int> v, int mid) {
    // cout<<mid<<endl;

   vector<int> temp=v;

    for (int i = v.size()-1; i>=2 ; i--) {
        if (v[i] > mid) {
            int num = min(v[i] - mid,temp[i]);
            num /= 3;
            v[i] -= (num * 3);
            v[i - 1] += num;
            v[i - 2] += (2 * num);
        }
    }

    int min1 = *min_element(v.begin(), v.end());

    // for (int i=0;i<v.size();i++) {
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;

    if (min1 >= mid) {
        // cout<<"true"<<endl;
        return true;
    }
    // cout<<"false"<<endl;
    return false;
}

void solve() {
    // Solution logic here
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i: v) {
        cin >> i;
    }
    int low = 1;
    int high =1e9;
    int ans = INT_MIN;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        // cout<<"low"<<low<<" mid"<<mid<<" high"<<high<<endl;
        if (possible(v, mid)) {
            ans = max(ans, mid);
            low = mid + 1;
        } else {
            high = mid - 1;
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
