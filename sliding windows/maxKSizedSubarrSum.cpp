
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

//time complexity = o(n)
//space complexity = o(1)


//2 for loops
int maxSubarraySumOfSizeK2(vector<int> &v,int k){
  int n=v.size();

  int sum=0;

  for(int i=0;i<k;i++){//o(k)
    sum+=v[i];
  }

  int ans=sum;

  for(int i=k;i<n;i++){//o(n-k)
    sum+=v[i]-v[i-k];//add ith element and remove i-kth element
    ans=max(ans,sum);
  }

  return ans;
}


//1 for loop
int maxSubarraySumOfSizek1(vector<int> &v,int k){
  int n=v.size();
  int sum=0;
  int ans=0;
  for(int i=0;i<n;i++){

    //add el
    sum+=v[i];

    //remove el
    if(i>=k){
      sum-=v[i-k];
    }

    //update ans
    if(i>=k-1){
      ans=max(ans,sum);
    }
  }
  return ans;
}

void solve() {
    // Solution logic here

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