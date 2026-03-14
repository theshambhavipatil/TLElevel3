
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
vector<int> v1={42,4,8,15,16,23};

int interactor(int val1,int val2){
  return v1[val1-1]*v1[val2-1];
}
int ask(int val1,int val2){
  if(testing==true){
    cout<<"? "<<val1<<" "<<val2<<endl;
      cout<<interactor(val1,val2)<<endl;
    return interactor(val1,val2);
  }
  else{
    cout<<"? "<<val1<<" "<<val2<<endl;
    int val;
    cin>>val;
    return val;
  }
}


void solve() {
    // Solution logic here
    vector<int> v={4,8,15,16,23,42};
    map<int,int> mp;
    vector<int> ans(v.size());
    //first three nos
//    cout<<"? "<<1<<2<<endl;
    int val1=ask(1,2);
//    cout<<"? "<<1<<3<<endl;
    int val2=ask(1,3);
//    cout<<"? "<<1<<4<<endl;
    int val3=ask(1,4);
//    cout<<"? "<<1<<5<<endl;
    int val4=ask(1,5);
  bool flag=false;
    if(val1%23==0 && val2%23==0 && flag==false){
      // cout<<1<<endl;
      // 1 23
      mp[23]=1;
      ans[0]=23;
      ans[1]=val1/23;
      mp[val1/23]=1;
      ans[2]=val2/23;
      mp[val2/23]=1;
      flag=true;

    }
    if(val1%15==0 && val2%15==0 && flag==false){
      // cout<<2<<endl;

      // 1 15
      mp[15]=1;
      ans[0]=15;
      ans[1]=val1/15;
      mp[val1/15]=1;
      ans[2]=val2/15;
      mp[val2/15]=1;
      flag=true;
    }
    if(val1%42==0 && val2%42==0 && flag==false){
      // cout<<3<<endl;

      //1 42
      mp[42]=1;
      ans[0]=42;
      ans[1]=val1/42;
      mp[val1/42]=1;
      ans[2]=val2/42;
      mp[val2/42]=1;
      flag=true;
    }

    if(val1%23==0  && flag==false){
      // cout<<4<<endl;
      //1 val1/23
      ans[0]=val1/23;
      mp[val1/23]=1;
      ans[1]=val1/ans[0];
      mp[val1/ans[0]]=1;
      ans[2]=val2/ans[0];
      mp[val2/ans[0]]=1;
      flag=true;

    }
   if(val2%23==0&& flag==false ) {
     // cout<<5<<endl;
     // 2 val2/23
     ans[2]=23;
     mp[23]=1;
     ans[0]=val2/23;
     mp[val2/23]=1;
     ans[1]=val1/ans[0];
     mp[val1/ans[0]]=1;
     flag=true;
   }
    if(val1%15==0&& flag==false ){
      // cout<<6<<endl;
      //1 val1/15
      ans[0]=val1/15;
      mp[val1/15]=1;
      ans[1]=val1/ans[0];
      mp[val1/ans[0]]=1;
      ans[2]=val2/ans[0];
      mp[val2/ans[0]]=1;
      flag=true;
    }
    if (val2%15==0&& flag==false) {
      // cout<<7<<endl;
      // 2 val2/15
      ans[2]=15;
      mp[15]=1;
      ans[0]=val2/15;
      mp[val2/15]=1;
      ans[1]=val1/ans[0];
      mp[val1/ans[0]]=1;
      flag=true;
    }
    if(val1%42==0&& flag==false){
      // cout<<8<<endl;
      //1 val1/42
      ans[0]=val1/42;
      mp[val1/42]=1;
      ans[1]=val1/ans[0];
      mp[val1/ans[0]]=1;
      ans[2]=val2/ans[0];
      mp[val2/ans[0]]=1;
      flag=true;
    }
    if(val2%42==0&& flag==false) {
      // cout<<9<<endl;
      //2 val2/42
      ans[2]=42;
      mp[42]=1;
      ans[0]=val2/42;
      mp[val2/42]=1;
      ans[1]=val1/ans[0];
      mp[val1/ans[0]]=1;
      flag=true;
    }
    else{
      set<int> s;
      s.insert(val1);
      s.insert(val2);
      if(s.find(32)!=s.end() && s.find(64)!=s.end() && flag==false){
        //1 4
        // cout<<10<<endl;
        ans[0]=4;
        mp[4]=1;
        ans[1]=val1/4;
        mp[val1/4]=1;
        ans[2]=val2/4;
        mp[val2/4]=1;
        flag=true;
      }
      if(s.find(32)!=s.end() && s.find(128)!=s.end() && flag==false){
        //1 8
        // cout<<11<<endl;
        ans[0]=8;
        mp[8]=1;
        ans[1]=val1/8;
        mp[val1/8]=1;
        ans[2]=val2/8;
        mp[val2/8]=1;
        flag=true;
      }
      if(s.find(64)!=s.end() && s.find(128)!=s.end() && flag==false){
        //1 16
        // cout<<12<<endl;
        ans[0]=16;
        mp[16]=1;
        ans[1]=val1/16;
        mp[val1/16]=1;
        ans[2]=val2/16;
        mp[val2/16]=1;
        flag=true;
      }

      //finding the next 3 numbers
      ans[3]=val3/ans[0];
      mp[val3/ans[0]]=1;
      ans[4]=val4/ans[0];
      mp[val4/ans[0]]=1;

      for(int i=0;i<v.size();i++){
        if(mp[v[i]]==0){
         ans[5]=v[i];
         break;
        }
      }
    }

    cout<<"! ";
    for(int i=0;i<ans.size();i++){
      cout<<ans[i]<<" ";
    }
    cout<<endl;
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