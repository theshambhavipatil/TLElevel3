
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


pair<int,int> intersection(pair<int, int> p1, pair<int, int> p2) {
  return {max(p1.first,p2.first), min(p1.second,p2.second)};
}
bool possible(vector<pair<int, int>> arr, int mid, int n) {
  pair<int,int> currRange={0,0};
  for (int i = 0; i < n; i++) {
    currRange={currRange.first-mid, currRange.second+mid};
    pair<int,int> desiredRange=arr[i];
    pair<int,int> range=intersection(currRange, desiredRange);
    if(range.first<=range.second){
      currRange={range.first, range.second};
    }
    else{
      return false;
    }
  }
  return true;
}
void solve() {
    // Solution logic here
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);

    for(auto &i :v){
      cin >> i.first >> i.second;
    }

    int lb=0;
    int ub=1e9;
    int ans=INT64_MAX;
    while(lb<=ub){
      int mid=lb+(ub-lb)/2;
      if(possible(v,mid,n)){
          ans=min(ans,mid);
          ub=mid-1;
      }
      else {
          lb=mid+1;
      }
    }
    cout << ans << endl;

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