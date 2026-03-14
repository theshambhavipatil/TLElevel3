
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

bool check(ll city,ll r,vector<ll> & v2){
   ll low=0;
   ll high=v2.size()-1;

   while(low<=high){
     ll mid=low + (high-low)/2;
     if(v2[mid]<city-r){
       low=mid+1;
     }
     else if(v2[mid]>city+r){
       high=mid-1;
     }
     else if(v2[mid] >=city-r && v2[mid]<=city+r){
       return true;
     }
   }

   return false;
}


void solve() {
    // Solution logic here
    ll n,m;
    cin>>n>>m;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
      cin>>v[i];
    }
    vector<ll> v2(m);
    for(ll i=0;i<m;i++){
      cin>>v2[i];
    }

    sort(v2.begin(),v2.end());

    ll minVal=0;
    ll maxVal=1e18;
    ll ans=INT_FAST64_MAX;

    while(minVal<=maxVal){
      ll mid= minVal + (maxVal-minVal)/2;
      // cout<<mid<<endl;
      bool flag=true;
      for(ll i=0;i<n;i++){
        if(check(v[i],mid,v2)!=true){
          flag=false;
          break;
        }
      }
      if(flag==true){
        ans=min(ans,mid);
        maxVal=mid-1;
      }
      else{
        minVal=mid+1;
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