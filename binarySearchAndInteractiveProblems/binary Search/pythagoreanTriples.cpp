
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

int sqrt(int x) {
    int start=1;
    int end=x;
    int ans=INT64_MAX;
    while(start<=end) {
        int mid=start+(end-start)/2;
        if(mid*mid>=x) {
            ans=min(ans, mid);
            end=mid-1;
        }
        else {
            start=mid+1;
        }
    }
    return ans;
}

void solve() {
    // Solution logic here
    int n;
    cin >> n;
    int val=sqrt(2*n);
    // cout<<val<<endl;
    int count=0;
    for(int i=3;i<val;i+=2) {
        int num=i*i;
        if (num<=2*n-1) {
            count++;
        }
    }
    cout << count << endl;
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
