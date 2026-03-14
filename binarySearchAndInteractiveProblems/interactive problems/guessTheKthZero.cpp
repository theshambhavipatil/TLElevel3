
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

vector<int> v={1,0,1,1,0,1};
vector<int> pre={1,1,2,3,3,4};
int interactor(int x){
 return pre[x-1];
}

bool testing=false;
int ask(int x){
    cout<<"? "<<1<<" "<<x<<endl;
 if(testing){
     cout<<"interactor: "<<interactor(x)<<endl;
   return interactor(x);
 }
 int res;cin>>res;return res;

}
void solve() {
    // Solution logic here
    int n,t;
    cin>>n>>t;
    int k;
    cin>>k;

    int low=0;
    int high=n-1;
    int count=0;
    int ans=INT_MAX;
    while(low<=high && count<=20) {
      int mid=low+(high-low)/2;
//      cout<<mid+1<<endl;
//      int val;
//      cin>>val;
      int val=ask(mid+1);
      int left=mid+1-val;
      if(left>=k) {
        ans=min(ans, mid+1);
        high=mid-1;
      }
      else {
        low=mid+1;
      }
      count++;
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
//    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}