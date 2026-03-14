
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
    int m,n;
    cin>>m>>n;

    vector<int> p(n,-1);
    for(int i=0;i<n;i++){
      cout<<1<<endl;
      int val;
      cin>>val;
      if(val==0){
        cout<<1<<endl;
        return;
      }
      if(val==-1){
        p[i]=1;
      }
    }


    int low=1;
    int high=m;
    int idx=0;
    while(low<=high){
      int mid=low+(high-low)/2;
      cout<<mid<<endl;
      int val;
      cin>>val;
      bool flag=(p[(idx++)%n]==1)?true:false;
      if(flag){
        //the judgement is correct
        if(val==0){
          cout<<mid<<endl;
          return;
        }
        if(val==-1){
          //we are on the left side
          low=mid+1;
        }
        else{
          high=mid-1;
        }
      }
      else{
          //the judgement is incorrect
          if(val==0){
              cout<<mid<<endl;
              return;
          }
          if(val==1){
              //we are on the left side
              low=mid+1;
          }
          else{
              high=mid-1;
          }
      }
    }




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