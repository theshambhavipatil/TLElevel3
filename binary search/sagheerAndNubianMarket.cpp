
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

map<ll, ll> mp;
pair<int,bool> possible(ll k,vector<ll> &v, ll s) {
  vector<ll> temp=v;
  for (ll i = 0; i < v.size(); i++) {
    temp[i]=v[i]+((i+1)*k);
  }


  sort(temp.begin(), temp.end());
  ll val=0;
  ll cost=0;
  for (ll i = 0; i < v.size(); i++) {
    if(s>=temp[i]) {
      // cout<<k<<" "s<<" "<<temp[i]<<endl;
      val++;
      s -= temp[i];
      cost+=temp[i];
      if (val==k) {
        break;
      }
    }
    else {
      break;
    }
  }
  if(val>=k){
    mp[k]=cost;
    return make_pair(cost,true);
  }
  return make_pair(-1,false);
}

void solve() {
    // Solution logic here
    ll n;
    cin >> n;
    ll s;
    cin >> s;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
      cin >> v[i];
    }

    ll start=1;
    ll end=n;
    ll ans=INT_MIN;
    ll ans1=INT_MIN;
    while (start<=end) {
      ll mid=start+(end-start)/2;
      pair<ll,bool> res=possible(mid,v,s);
      if(res.second) {
        if (ans<=mid) {
          ans=mid;
          ans1=mp[mid];
        }
        start=mid+1;
      }
      else {
        end=mid-1;
      }
    }

  if(ans==INT_MIN && ans1==INT_MIN) {
    cout<<0<<" "<<0<<endl;
    return;
  }

    cout<<ans<<" "<<ans1<<endl;

}

signed main() {
    FAST_IO;
    


    int t = 1;

    while (t--) {
        solve();
    }
    
    return 0;
}