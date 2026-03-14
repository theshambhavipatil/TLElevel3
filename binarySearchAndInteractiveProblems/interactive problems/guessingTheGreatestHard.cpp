
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


int query(int l,int r){
  cout<<"? "<<l<<" "<<r<<endl;
  int val;cin>>val;return val;
}

int right(int l,int r){
  //nnnyyyyy
  int val=l-1;
  int ans=r;
    while(r>=l){
      int mid=l+(r-l)/2;
      if(query(val,mid)==val){
        ans=mid;
        r=mid-1;
      }
      else{
        l=mid+1;
      }
    }
    return ans;
}

int left(int l,int r){
  //yyyynnnn
  int val=r+1;
  int ans=l;
  while(l<=r){
    int mid=l+(r-l)/2;
    if(query(mid,val)==val){
      ans=mid;
      l=mid+1;
    }
    else{
      r=mid-1;
    }
  }
  return ans;
}


void solve() {
    // Solution logic here
    int n;
    cin>>n;

    if (n==2) {
      cout<<"? "<<1<<" "<<2<<endl;
      int val;
      cin>>val;
      if(val==1) {
        cout<<"! "<<2<<endl;
        return;
      }
      else {
        cout<<"? "<<1<<endl;
        return;
      }
    }
    int pivot=query(1,n);
  if(pivot==1) {
    pivot=right(2,n);
  }
   else if(query(1,pivot)==pivot){
      pivot=left(1,pivot-1);
    }
    else{
      pivot=right(pivot+1,n);
    }

    cout<<"! "<<pivot<<endl;

}

signed main() {
    FAST_IO;

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    //     freopen("Error.txt", "w", stderr);
    // #endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}