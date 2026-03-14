
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

bool possible(int day,int m,int k,vector<int> &val){
  vector<int> temp(val.size());
  for(int i=0;i<val.size();i++){
    if(val[i]<=day){
      temp[i]=1;
    }
    else{
      temp[i]=0;
    }
  }

  int count=0;
  int num=0;
  bool flag=false;
  for(int i=0;i<val.size();i++){
    if(temp[i]==1 && flag==false){
      flag=true;
      num++;
    }
    if (temp[i]==0 && flag==true) {
      flag=false;
      num=0;
    }
    if(temp[i]==1 && flag==true){
      num++;
    }
    if(num==k){
      num=0;
      count++;
      flag=false;
    }
  }

  cout<<count<<endl;
  if(count>=m){
    return true;
  }
  else{
    return false;
  }
}

int minDays(vector<int>& bloomDay, int m, int k) {
  int lowerBound=*min_element(bloomDay.begin(), bloomDay.end());
  int upperBound=*max_element(bloomDay.begin(), bloomDay.end());
  int ans=INT_MAX;

  //ffttt
  while(lowerBound<=upperBound){
    int mid=lowerBound+(upperBound-lowerBound)/2;
    if(possible(mid,m,k,bloomDay)){
      upperBound=mid-1;
      ans=min(ans,mid);
    }
    else{
      lowerBound=mid+1;
    }
  }

  if(ans==INT_MAX){
    ans=-1;
  }
  return ans;
}

void solve() {
    // Solution logic here
  
    vector<int> bloom={7,7,7,7,12,7,7};
    int val=minDays(bloom,2,3);
    cout<<val<<endl;
}

signed main() {
    FAST_IO;
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif

    int t = 1;

    while (t--) {
        solve();
    }
    
    return 0;
}