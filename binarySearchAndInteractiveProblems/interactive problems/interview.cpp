
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

bool testing=false;
vector<int> v1={1,4,7,11,16};

int interactor(int val){
return v1[val];
}
int ask(int val){
  if(testing==true){
    cout<<"? "<<val+1<<" ";
    for(int i=1;i<=val+1;i++){
      cout<<i<<" ";
    }
    cout<<endl;
   return interactor(val);
  }
  else{
    cout<<"? "<<val+1<<" ";
    for(int i=1;i<=val;i++){
      cout<<i<<" ";
    }
    cout<<val+1<<endl;
    cout<<endl;

    int val;
    cin>>val;
    return val;
  }
}

void solve() {
    // Solution logic here
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    vector<ll> pre(n);
    pre[0] = v[0];
    for (int i = 1; i < n; i++) {
      pre[i] = pre[i - 1] + v[i];
    }
    int start=0;
    int end=n-1;
    int ans=INT_MAX;
    while (start<=end) {
      int mid=start+(end-start)/2;
      if(ask(mid)>pre[mid]){
        end=mid-1;
        ans=min(ans, mid);
      }
      else{
        start=mid+1;
      }
    }
    cout<<"! "<<ans+1<<endl;
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