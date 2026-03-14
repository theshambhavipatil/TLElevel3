
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


bool possible(int x,int k,vector<int>& val){
  //o(n)
  int usedWorkers=1;
  int currentWorkload=0;
  for(auto work :val){
    if(currentWorkload+work<=x){
      currentWorkload=currentWorkload+work;
    }
    else{
      if(usedWorkers==k){
        return false;
      }
        if(work>x){
          return false;
        }
        currentWorkload=work;
        usedWorkers++;
    }
  }
  return true;
}



void solve() {
    // Solution logic here
    //o(log(searchspace)*n)
    //search space (worst case)
    //lowerend=0 upperend=10^18
    //log(search space) =60
    // lowerend=0 upperend=10^9
    //log(search space) =30
    int n,k;
    cin>>n>>k;
    vector<int> val(n);
    for(int i=0;i<n;i++){
      cin>>val[i];
    }
//    int start=*max_element(val.begin(),val.end());
//    int end=accumulate(val.begin(),val.end(),0);
    //as time complexity is logarithmic in terms of search space
    //so it wont be of much harm to take start as 0 and end as 1e9

    int start=0;
    int end=1e9;
    int mid;
    int ans=1e9;

    //fffftttt
    while(start<=end){
      mid=start+(end-start)/2;
      if(possible(mid,k,val)){
        ans=min(ans,mid);
        end=mid-1;
      }
      else{
        start=mid+1;
      }
    }

    cout<<ans<<endl;

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