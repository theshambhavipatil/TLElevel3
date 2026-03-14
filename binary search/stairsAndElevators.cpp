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

vector<int> stairs;
vector<int> elevators;

int possibleStairs(int cl,int x1,int y1,int x2,int y2,int v) {
  int temp1=min(y1,y2);
  int temp2=max(y1,y2);
  y1=temp1;
  y2=temp2;
  int v1=min(x1,x2);
  int v2=max(x1,x2);
  x1=v1;
  x2=v2;

  if (cl==0) {
    return INT_MAX;
  }
  int t1=0;
  int low=0;
  int high=stairs.size()-1;
  int ans=INT_MAX;
  while(low<=high){
    int mid=low+(high-low)/2;
    if(stairs[mid]>=y1){
      ans=min(ans,stairs[mid]);
      high=mid-1;
    }
    else{
      low=mid+1;
    }
  }
  if (ans==INT_MAX) {
    // nnnnnnn (everything is smaller)
    int val1=abs(y1-stairs[cl-1]);
    t1=abs(y2-y1)+(2*val1)+abs(x2-x1);
    return t1;
  }
  else {
    // nnnnnnyyyyyyyy (we have the smallest y)
    if (ans>=y1 && ans<=y2) {
      t1+=abs(y1-y2)+abs(x2-x1);
      return t1;
    }
    else {
      // y bigger than y2
      int temp2=abs(ans-y2);

      int start=0;
      int end=stairs.size()-1;
      int ans=INT_MIN;
      while(start<=end){
        int mid=start+(end-start)/2;
        if(stairs[mid]<y1){
          ans=max(ans,stairs[mid]);
          start=mid+1;
        }
        else{
          end=mid-1;
        }
      }
      // if there is anything present that is less than y1
      if (ans!=INT_MIN) {
        int temp3=abs(ans-y1);
        int minVal=min(temp2,temp3);
        t1=abs(y2-y1)+(2*minVal)+abs(x2-x1);
        return t1;
      }
      if (ans==INT_MIN) {
        t1=abs(y2-y1)+abs(x2-x1)+(2*temp2);
        return t1;

      }

    }
  }
}


int possibleElevators(int ce,int x1,int y1,int x2,int y2,int v) {
  int temp1=min(y1,y2);
  int temp2=max(y1,y2);
  int v1=min(x1,x2);
  int v2=max(x1,x2);
  x1=v1;
  x2=v2;
  y1=temp1;
  y2=temp2;

  if (ce==0) {
    return INT_MAX;
  }
  int t1=0;
  int low=0;
  int high=elevators.size()-1;
  int ans=INT_MAX;
  while(low<=high){
    int mid=low+(high-low)/2;
    if(elevators[mid]>=y1){
      ans=min(ans,elevators[mid]);
      high=mid-1;
    }
    else{
      low=mid+1;
    }
  }
  if (ans==INT_MAX) {
    // nnnnnnn (everything is smaller)
    // cout<<"elevator chosen : " <<ans<<endl;
    int val1=abs(y1-elevators[ce-1]);
    t1=abs(y2-y1)+(2*val1)+abs((x2-x1)/v);
    // cout<<val1<<endl;
    // cout<<abs(y2-y1)<<endl;
    // cout<<(x2-x1)/v<<endl;
    if ((x2-x1)%v!=0) {
      t1++;
    }
    return t1;
  }
  else {
    // nnnnnnyyyyyyyy (we have the smallest y)
    if (ans>=y1 && ans<=y2) {
      // cout<<"elevator chosen : " <<ans<<endl;
      t1+=abs(y1-y2)+abs((x2-x1)/v);
      // cout<<abs(y2-y1)<<endl;
      // cout<<(x2-x1)/v<<endl;
      if ((x2-x1)%v!=0) {
        t1++;
      }
      return t1;
    }
    else {
      // y bigger than y2
      int temp2=abs(ans-y2);
      // cout<<"temp2 "<<ans<<endl;
      // cout<<"temp2 "<<y2<<endl;
      int start=0;
      int end=elevators.size()-1;
      int ans=INT_MIN;
      while(start<=end){
        int mid=start+(end-start)/2;
        if(elevators[mid]<y1){
          ans=max(ans,elevators[mid]);
          start=mid+1;
        }
        else{
          end=mid-1;
        }
      }
      // if there is anything present that is less than y1
      if (ans!=INT_MIN) {
        // cout<<"elevator chosen : " <<ans<<endl;
        int temp3=abs(ans-y1);
        int minVal=min(temp2,temp3);
        t1=abs(y2-y1)+(2*minVal)+abs((x2-x1)/v);
        if ((x2-x1)%v!=0) {
          t1++;
        }
        return t1;
      }
      if (ans==INT_MIN) {
        // cout<<"elevator chosen : " <<ans<<endl;
        // cout<<"chosen el :"<<temp2<<endl;
        t1=abs(y2-y1)+abs((x2-x1)/v)+(2*temp2);
        if ((x2-x1)%v!=0) {
          t1++;
        }
        return t1;

      }

    }
  }
}




void solve() {
    // Solution logic here
    int n,m;
    cin>>n>>m;
    int cl,ce;
    cin>>cl>>ce;
    int v;
    cin>>v;

    for(int i=0;i<cl;i++){
      int val;
      cin>>val;
      val--;
      stairs.push_back(val);
    }
    for(int i=0;i<ce;i++){
      int val;
      cin>>val;
      val--;
      elevators.push_back(val);
    }

    int q;
    cin>>q;

    while(q--){
      int low=0;
      int high=1e9;
      int x1,y1,x2,y2;
      cin>>x1>>y1>>x2>>y2;
      x1--;
      y1--;
      x2--;
      y2--;
      if (x1==x2) {
        cout<<abs(y2-y1)<<endl;
        continue;
      }
      int ans=INT_MAX;
      // cout<<"query "<<endl;

      // cout<<"low "<<low<<" mid"<<mid<<" high"<<high<<endl;
      int val1=possibleStairs(cl,x1,y1,x2,y2,v);
      int val2=possibleElevators(ce,x1,y1,x2,y2,v);
      ans=min(val1,val2);

      cout<<ans<<endl;
    }


}

signed main() {
    FAST_IO;

    int t = 1;

    while (t--) {
        solve();
    }

    return 0;
}