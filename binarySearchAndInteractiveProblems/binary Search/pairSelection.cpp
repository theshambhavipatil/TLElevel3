
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

bool f(lld mid,vector<lld>a,vector<lld> b,int n,int k) {
    vector<lld> transformedArr(n);
    for(int i=0;i<n;i++) {
        transformedArr[i] = a[i] -(b[i]*mid);
    }
    sort(transformedArr.rbegin(), transformedArr.rend());
    lld sum=0;
    for(int i=0;i<k;i++) {
        sum += transformedArr[i];
    }
    return sum>=0;
}

void solve() {
    // Solution logic here
    int n,k;
    cin>>n>>k;

    vector<lld> a(n),b(n);
    for(int i=0;i<n;i++) {
      cin>>a[i]>>b[i];
    }


    lld low=0;
    lld high=1e5; // we would have n integers in numerator & denominator max case (1e5)
    //numerator sum=1e5(no of values)*1e5(max value) =1e10
    //denominator=1e5(no of values)*1(min value)=1e5

    for(int i=0;i<60;i++) {
      lld mid=low+(high-low)/2;
      if(f(mid,a,b,n,k)){
        low=mid;
      }
      else{
        high=mid;
      }
    }

    cout<<setprecision(7)<<fixed;
    cout<<low<<endl;


}

signed main() {
    FAST_IO;


    int t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}