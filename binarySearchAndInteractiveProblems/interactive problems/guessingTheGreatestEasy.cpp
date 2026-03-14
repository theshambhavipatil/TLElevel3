
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

void solve() {
    // Solution logic here
    int n;
    cin >> n;

    int low=1;
    int high=n;
    int ans=INT_MAX;
    while (low<=high) {
        cout<<"? "<<low<<" "<<high<<endl;
        int val;
        cin>>val;
        if (high==low+1) {
            if (val==low) {
                ans=high;
                break;
            }
                ans=low;
                break;


        }
        int mid=(low+high)/2;

        if (val>=mid) {
            cout<<"? "<<mid<<" "<<high<<endl;
            int val2;
            cin>>val2;
            if (val2==val) {
                low=mid;
            }
            else {
                high=mid;
            }
        }
        else {
            cout<<"? "<<low<<" "<<mid<<endl;
            int val3;
            cin>>val3;
            if (val3==val) {
            high=mid;
            }
            else {
           low=mid;
            }
        }
    }

    cout<<"! "<<ans<<endl;

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