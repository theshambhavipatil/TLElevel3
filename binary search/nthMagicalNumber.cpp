
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



int nthMagicalNumber(int n, int a, int b) {
   long long start=1;
   long long end=1e15;
   long long ans=-1;

   while( start <= end ) {
     long long mid=start+(end-start)/2;
     long long cnta=mid/a;
     long long cntb=mid/b;
     long long cntLcm=mid/lcm(a, b);

     long long val=cnta+cntb-cntLcm;
     if( val==n) {
       ans=mid;
       end=mid-1;
     }
     else if(val<n) {
       start=mid+1;
     }
     else {
       end=mid-1;
     }
   }

     ans%=MOD;
     return (int)ans;




}


void solve() {
    // Solution logic here

}

signed main() {
    FAST_IO;
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}