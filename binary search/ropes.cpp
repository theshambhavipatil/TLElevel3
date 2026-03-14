
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

int n,k;

bool possible(vector<int> temp,double mid,int k){
  int t1=0;
  for(int i=0;i<temp.size();i++){
    int val=floor(temp[i]/mid);
    t1+=val;
    // cout<<temp[i]<<" "<<val<<endl;
  }
  // cout<<t1<<endl;
  if(t1>=k){
    return true;
  }
  return false;

}
void solve() {
    // Solution logic here
    vector<int> temp(n);
    for(int i = 0; i < n; i++) {
      cin >> temp[i];
    }

    double start=1e-4;
    double end=1e7;

    for(int i = 1; i <= 50; i++) {
      double mid=start+((end-start)/2);
        // cout<<" start "<<start<<" mid "<<mid<<"end"<<end<<endl;
      if(possible(temp,mid,k)){
        start = mid;
      }
      else{
        end = mid;
      }
    }

  cout<<setprecision(7)<<endl;
  cout << start  << endl;

}

signed main() {
    FAST_IO;

    cin >> n >> k;
    int t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}