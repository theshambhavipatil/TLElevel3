//
// Created by Admin on 31-01-2026.
//


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

bool comparator(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }
vector<int> smallestRange(vector<vector<int>>& nums) {
    // int val1=nums.size(), val2=nums[0].size();
    // cout<<val1<<" "<<val2<<endl;
    vector<pair<int, int>> v;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums[i].size(); j++) {
            v.push_back({nums[i][j], i});
        }
    }

    sort(v.begin(), v.end(),comparator);

    // for (int i = 0; i < v.size(); i++) {
    //     cout << v[i].first << " " << v[i].second << endl;
    // }
    // cout<<v.size()<<endl;
    map<int, int> mp;
    vector<int> ans;
    int val=INT_MAX;
    for (int left=0,right=0;right<v.size();right++) {
        // cout<<left<<" "<<right<<endl;
        mp[v[right].second]++;
        while (mp.size()>=nums.size() && right>=left) {
            mp[v[left].second]--;
            if (mp[v[left].second]==0) {
                mp.erase(v[left].second);
            }
            left++;
        }
        val=min(val,v[right].first-v[left].first);
        if (val==v[right].first-v[left].first && mp.size()==nums.size()) {
            cout<<v[left].first<<" "<<v[right].first<<endl;
            ans={v[left].first,v[right].first};
        }

    }
    return ans;

}


void solve() {
    // Solution logic here
    vector<vector<int>> nums={{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    vector<int> ans=smallestRange(nums);
    cout<<ans[0]<<" "<<ans[1];
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