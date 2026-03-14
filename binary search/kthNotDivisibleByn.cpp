
#include <bits/stdc++.h>
#define int long long
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

bool possible(int mid,int n,int k) {
    int val1=mid/n;
    int val2=mid-val1; // not divisible

    // cout<<val2<<" ";
    if (val2>=k) {
        // cout<<"true"<<endl;
        return true;
    }
    // cout<<"false"<<endl;
    return false;
}
void solve() {
    // Solution logic here
    int n,k;
    cin>>n>>k;

    int start=1;
    int end=1e18;
    int ans=INT_FAST64_MAX;
    while( start <= end ) {
        ll mid=start+(end-start)/2;
        // cout<<"start "<<start<<" "<<mid<<" "<<"end "<<end<<endl;
        if (possible(mid,n,k)) {
            ans=min(ans,mid);
            end=mid-1;
        }
        else {
            start=mid+1;
        }
    }

    cout<<ans<<endl;
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