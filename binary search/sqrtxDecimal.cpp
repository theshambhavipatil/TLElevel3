
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
    double x;
    cin>>x;

    double precision=1e-14;

    double low=0;
    double high=x;
    double ans=0;
    int iterations=100;
    cout<<setprecision(20)<<endl;

    for (int i=0;i<iterations;i++) { // high-low>=precision
      double mid=low + (high-low)/2;
        cout<<"low"<<" "<<low<<" "<<"mid"<<" "<<mid<<" "<<"high"<<" "<<high<<" ";
      if(mid*mid<=x){
        ans=max(ans,mid);
        low=mid+precision;
          cout<<"new low :"<<low;
          cout<<" "<<1<<" ";
          cout<<endl;
      }
      else{
        high=mid-precision;
          cout<<2<<" ";
          cout<<endl;
      }
    }


    cout<<ans<<endl;
}

signed main() {
    FAST_IO;

   // double a=62676.74993169317167;
   // double b=62676.74993169317895;
   // cout<<setprecision(20)<<endl;
   // cout<< (b+a)/2<<endl;

    //mid+precision=mid
    // cout<<setprecision(20)<<endl;
    // cout<<62676.749931693149847+(1e-14)<<endl;

    //mid-precision=mid
    // cout<<setprecision(20)<<endl;
    // cout<<62676.749931693178951-(1e-14)<<endl;
    
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     freopen("Error.txt", "w", stderr);
// #endif

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}