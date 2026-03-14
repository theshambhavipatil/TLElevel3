
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


int getIdx2(int val,vector<int> &v,int start) {
    int end=v.size()-1;
    int ans=INT_MIN;
    while(start<=end) {
        int mid=start+(end-start)/2;
        if (v[mid]<=2*val) {
            ans=max(ans,mid);
            start=mid+1;
        }
        else {
            end=mid-1;
        }
    }
    return ans;
}

void solve() {
    // Solution logic here
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        v[i]=abs(v[i]);
    }

    sort(v.begin(), v.end());

    int count=0;
    for (int i = 0; i < n; i++) {
        int val2=getIdx2(v[i],v,i+1);
        if (val2!=INT_MIN) {
          count+=abs(i-val2);
        }
    }

    cout << count << endl;



}

signed main() {
    FAST_IO;
    

    int t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}