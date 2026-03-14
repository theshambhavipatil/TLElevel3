
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


bool query(int low,int mid){
  cout<<"? "<<low<<" "<<mid<<endl;
  int count=0;
  int num=mid-low+1;
  for(int i=0;i<num;i++){
    int val;
    cin>>val;
    if(val>=low && val<=mid){
      count++;
    }
  }

  if(count%2==0){
    return false;
  }
  return true;
}


void solve() {
    // Solution logic here
    int n;
    cin >> n;
    int low=1;
    int high=n;
    int ans=INT_MAX;
    while (low<=high) {
      int mid=low+(high-low)/2;
      bool flag=query(low,mid);
      if(flag){
        ans=mid;
        high=mid-1;
      }
      else{
        low=mid+1;
      }
    }

    cout<<"! "<<ans<<endl;
}

signed main() {
    FAST_IO;
    
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    freopen("Error.txt", "w", stderr);
//#endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}