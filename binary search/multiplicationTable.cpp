
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

bool possible(int factor,int c,int n) {
    int count=0;
    for(int i=1;i<=n;i++) {
        if (c/i >=n) {
            count+=n;
            // cout<< i<<" "<<n<<endl;
        }
        else {
            count+=c/i;
            // cout<< i<<" "<<c/i<<endl;
        }
    }
    // cout<<factor<<" "<<"count "<<count<<endl;
    if(count>=factor+1) {
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
    int start=1;
    int end=n*n;
    int factor=(n*n)/2;
    int ans=INT_FAST64_MAX;
    while (start<=end) {
        int mid = start + (end-start)/2;
        // cout<<"start "<<start<<" "<<"mid "<<mid<<" "<<"end "<<end<<endl;
        if (possible(factor,mid,n)) {
            end = mid-1;
            ans=min(ans,mid);
        }
        else {
            start=mid+1;
        }

    }
    cout << ans<< endl;


}

signed main() {
    FAST_IO;
    
   // cout<<(999999*1ll*999999)/2<<endl;

    int t = 1;

    while (t--) {
        solve();
    }
    
    return 0;
}