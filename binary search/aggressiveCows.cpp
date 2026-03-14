
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


bool possible(int distance,vector<int> v1,int c){
  int count=1;
  int lastPlaced=v1[0];
  for(int i=1;i<v1.size();i++){
    if(abs(v1[i]-lastPlaced)>=distance){
      count++;
      lastPlaced=v1[i];
    }
  }
  if(count>=c){
    return true;
  }
  return false;
}

void solve() {
    // Solution logic here
    int n,c;
    cin>>n>>c;
    vector<int> v(n);
    for(int i=0;i<n;i++){
      cin>>v[i];
    }
  sort(v.begin(),v.end());
    int ans=INT_MIN;
    int lower_bound=1,upper_bound=v[n-1]-v[0];
    while(lower_bound<=upper_bound){
      int mid=lower_bound+(upper_bound-lower_bound)/2;
      if(possible(mid,v,c)){
        ans=max(ans,mid);
        lower_bound=mid+1;

      }
      else{
        upper_bound=mid-1;
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