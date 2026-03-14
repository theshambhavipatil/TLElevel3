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

void solve() {
    // Solution logic here
    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }

    map<int,vector<int>> mp1;
    for(int i=0;i<n;i++) {
        mp1[v[i]].push_back(i);
    }

    sort(v.begin(),v.end());

    map<int,int> mp;

    for (auto it:v) {
        mp[it]++;
    }

    if (n<=2) {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }

    int sum=0;
    for (int left=0,right=1;right<n;right++) {
        while (x-(v[left]+v[right])>=v[right]  && left<right) {
            int find=x-(v[left]+v[right]);
            // cout<<left<<" "<<right<<endl;
            // cout<<v[left]<<" "<<v[right]<<" "<<find<<endl;
            // cout<<"find"<<find<<endl;
            cout<<mp[find]<<endl;

            if (mp[find]>0) {
                int idx=-1;

                for (int i=right+1;i<n;i++) {
                    if (v[i]==find) {
                        idx=i;
                        break;
                    }
                }
                if (idx!=-1)
                {
                    int idx1=mp1[v[left]].back();
                    mp1[v[left]].pop_back();
                    int idx2=mp1[v[right]].back();
                    mp1[v[right]].pop_back();
                    int idx3=mp1[v[idx]].back();
                    mp1[v[idx]].pop_back();
                    cout<<idx1+1<<" "<<idx2+1<<" "<<idx3+1<<endl;
                    return;
                }

            }

            left++;
        }
    }

    cout<<"IMPOSSIBLE"<<endl;

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