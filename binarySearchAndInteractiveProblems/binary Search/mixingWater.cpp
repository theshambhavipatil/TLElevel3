
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

pair<bool,int> possible(int mid,int t,int h,int c) {
    int val=mid/2;
    int val2=mid%2;
    int res=(val+val2)*(h-t);
    res+=(val*(c-t));
    cout<<res<<endl;
    if (res>=0) return {true,res};
    return {false,-1};
}

void solve() {
    // Solution logic here
    lld h,c,t;
    cin>>h>>c>>t;
    // cout<<(t-h)/((h+c)-(2*t))<<endl;

    lld low=1;
    lld high=1e9;
    ll ans=1;

    if (t>=h) {
        cout<<1<<endl;
        return;
    }
    if (t<=(h+c)/2) {
        cout<<2<<endl;
        return;
    }

    lld difference=abs(t-h);

   for (int i=1;i<=100;i++) {
        ll mid=low+(high-low)/2;
        lld val=(((mid)*h*1.0)+((mid-1)*c))/((2*mid-1));
        // cout<<"mid "<<mid<<" "<<"val"<<val<<" "<<t<<endl;
        // cout<<"low"<<low<<"high"<<high<<endl;
       if (abs(val-t)<difference) {
           difference=abs(val-t);
           ans=mid;
       }
       if (val>=t) {
           low=mid;
        }
        else {
            high=mid;
        }

    }

    if (ans==-1) {
        cout<<1<<endl;
        return;
    }

    cout<<(2*ans)-1<<endl;




    // cout<<(t-h)/((h+c)-(2*t))<<endl;
    //
    // lld sum=0;
    // int val=0;
    // cout<<setprecision(8)<<fixed;
    // for(int i=0;i<=100;i++) {
    //     sum+=(val%2==1)?c:h;
    //     val++;
    //     if (val%2==1) {
    //         cout<<sum/val<<endl;
    //     }
    // }

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