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

bool isPossible(vector<vector<int>> v1,ll mid ,ll k,int n) {
    int sum1=0;
    int count1=0;

    for(int i=0;i<n;i++) {
        if (v1[i][0]>mid) {
            sum1+=(v1[i][0]-mid)*v1[i][1];
            count1+=(v1[i][0]-mid);

            // cout<<v1[i][0]<<" "<<sum1<<" "<<count1<<endl;
        }
    }
    for (int i=0;i<n;i++) {
        if (v1[i][0]<mid && count1>0) {
            int need=mid-v1[i][0];
            if (need<=count1) {
                sum1+=need*v1[i][2];
                count1-=need;
                // cout<<v1[i][0]<<" "<<sum1<<" "<<count1<<endl;
            }
            else {
                //need > count1
                sum1+=(count1)*v1[i][2];
                count1=0;
                // cout<<v1[i][0]<<" "<<sum1<<" "<<count1<<endl;
                break;
            }
        }
    }

    if (sum1<=k && count1==0) {
        return true;
    }
    return false;
}


void solve() {
    // Solution logic here
    int n,k;
    cin>>n>>k;
    vector<vector<int>> v1(n,vector<int>(3));

    for(int i=0;i<n;i++) {
     cin>>v1[i][0]>>v1[i][1]>>v1[i][2];
    }



    sort(v1.begin(),v1.end(),[](const vector<int>& a, const vector<int>& b) {
         return a[2] < b[2];
     });

    int low=1,high=1e6+1;
    int ans=INT_MAX;
    while(low<=high) {
        int mid=low+(high-low)/2;
        // cout<<low<<" "<<mid<<" "<<high<<endl;
        if (isPossible(v1,mid,k,n)) {
            // cout<<"yes"<<endl;
            ans=min(ans,mid);
            high=mid-1;
        }
        else {
            // cout<<"no"<<endl;
            low=mid+1;
        }
    }

    if (ans==INT_MAX) {
        ans=*max_element(v1[0].begin(),v1[0].end());
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
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}