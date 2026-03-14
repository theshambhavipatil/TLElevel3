
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


int binarySearch(int l,vector<int> &v){
  int start=0;
  int end=v.size()-1;

  int ans=INT_MIN;
  while(start<=end){
      int mid=start+(end-start)/2;
    if(v[mid]==l){
      ans=max(ans,mid+1);
      return ans;
    }
    else if(v[mid]<l){
      ans=max(ans,mid+1);
      start=mid+1;
    }
    else{
      end=mid-1;
    }
  }
  return ans;
}

void solve() {
    // Solution logic here
    int n;
    cin >> n;
    int l,r;
    cin>>l>>r;
    vector<int> v(n);
    for(int i=0;i<n;i++){
      cin>>v[i];
    }
    int val1=binarySearch(l-1,v);
    int val2=binarySearch(r,v);
    cout<<val2-val1<<endl;
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