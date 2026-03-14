#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
using namespace std;
using namespace __gnu_pbds;


typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

template<class T>
using ordered_set = tree<
    T,
    null_type,
    less<T>, // comparison (can use less_equal<T> for multiset-like)
    rb_tree_tag,
    tree_order_statistics_node_update>;

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

bool possible(vector<int> v,int mid,int k,int sum,vector<int> pre) {
    //mid operations
    int reduce=sum-k;
    // cout<<"reduce "<<reduce<<endl;

    if (reduce<=0) {
        return true;
    }

    bool flag=false;
    int num1=0;



    // i ... n-1  // 5 9



    for(int i=0;i<=mid;i++) { //mid
        int val=v[0];
        int val2=pre[ll(v.size())-1]-pre[max((ll)v.size()-mid+i-1,(ll)0)];
        int val3=val2-(min(mid-i,(ll)v.size()-1)*(val-i));
        // cout<<i+val3<<endl;
        num1=max(num1,i+val3);
        if (num1>=reduce) {
            // cout<<"YES"<<endl;
            return true;
        }
    }


    if (num1>=reduce) {
        // cout<<"YES"<<endl;
        return true;
    }
    // cout<<"NO"<<endl;
    return false;


}

void solve() {
    // Solution logic here
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int sum=accumulate(v.begin(),v.end(),0);

    int idx=-1;
    for(int i=0;i<n;i++) {
        if (v[i]>k/n) {
            idx=i;
            break;
        }
    }

    if (n==1) {
        int val=v[0]-k;
        cout<<val<<endl;
        return;
    }
    if (sum<=k) {
        cout<<0<<endl;
        return;
    }

    vector<int> pre(v.size(),0);
    pre[0]=v[0];
    for (int i=1;i<v.size();i++) {
        pre[i]=pre[i-1]+v[i];
    }

    //binary search on no of operations
    int low=0;
    int high=(ll)2e5+1;
     int ans=INT64_MAX;
    //nnnnnnyyyyyyy
    while(low<=high) {
        int mid=low+(high-low)/2;
        // cout<<"low "<<low<<"  "<<"mid "<<" "<<mid<<" "<<"high"<<high<<endl;
        if(possible(v,mid,k,sum,pre)) {
            ans=min(ans,mid);
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }

    cout<<ans<<endl;

}

signed main() {
    FAST_IO;

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     freopen("Error.txt", "w", stderr);
// #endif

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}