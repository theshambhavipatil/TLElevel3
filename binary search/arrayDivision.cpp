
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

bool possible(int mid,int k,vector<int> &v) {
    int count=0;
    int sum=0;
    for(int i=0;i<v.size();i++) {
        if (sum+v[i]<=mid) {
            sum+=v[i];
        }
        else {
            count++;
            sum=v[i];
        }
    }
    count++;
    if (count>k) {
        return false;
    }
    return true;
}

void solve() {
    // Solution logic here
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
      cin>>v[i];
    }
    int low=*max_element(v.begin(),v.end());
    int high=INT_FAST64_MAX;
    int ans=INT_FAST64_MAX;

    while(low<=high) {
        int mid=low+(high-low)/2;
        if (possible(mid,k,v)) {
            ans=min(ans,mid);
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }
    cout<<ans<<endl;

}

signed main() {
    FAST_IO;
    

    int t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}