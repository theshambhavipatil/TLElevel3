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

bool possible(int queries,vector<int> query,vector<pair<int,int>> segments,int n,int m) {
  vector<int> arr(n,0);
  for(int i=0;i<queries;i++) {
    arr[query[i]] = 1;
  }
    vector<int> prefSum(n);
    prefSum[0] = arr[0];
  for(int i=1;i<n;i++) {
    prefSum[i]=arr[i]+prefSum[i-1];
  }

  for(int i=0;i<m;i++) {
    int l=segments[i].first;
    int r=segments[i].second;
    int segmentSize=r-l+1;
    int num=prefSum[r]-((l>0) ? prefSum[l-1] : 0);
    if(num>segmentSize/2){
      return true;
    }
  }
    return false;
}

void solve() {
    // Solution logic here
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> v(m);
    for(int i=0;i<m;i++){
      cin>>v[i].first>>v[i].second;
      v[i].first--;
      v[i].second--;
    }
    int q;
    cin>>q;

    vector<int> v2(q);
    for(int i=0;i<q;i++){
      cin>>v2[i];
      v2[i]--;
    }
    int start=1;
    int end=q;
    ll ans=INT64_MAX;

    while(start<=end){
      int mid=start+(end-start)/2;
        // cout<<"start "<<start<<" mid "<<mid<<" end "<<end<<endl;
      if(possible(mid,v2,v,n,m)){
        ans=min(ans,mid);
          end=mid-1;
      }
        else {
            start=mid+1;
        }
    }
    if(ans==INT64_MAX) {
        ans=-1;
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