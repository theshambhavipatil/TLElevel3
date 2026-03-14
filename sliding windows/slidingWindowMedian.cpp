#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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


// 2 multiset approach
vector<double> slidingWindowMedian1(vector<int> &nums, int k) {
    multiset<int> lo, hi;

    //lambda func
    auto balance=[&]() {
        if (lo.size()-1>hi.size() && lo.size()) {//lo has more elements than needed , high has less elements than needed
            hi.insert(*lo.rbegin());
            lo.erase(prev(lo.end()));
        }
        if (hi.size()>lo.size()) {
            lo.insert(*hi.begin());
            hi.erase(hi.begin());
        }
    };

    vector<double> ans;
    int n=nums.size();
    for (int i=0; i<n; i++) {
        //insert an element
        if (lo.empty() || nums[i]<=*lo.rbegin()) {
            lo.insert(nums[i]);
        }
        else {
            hi.insert(nums[i]);
        }
        balance();

        //delete an element
        if (i>=k) {
            ll out=nums[i-k];
            if (out<=*lo.rbegin()) {
                lo.erase(lo.find(out));
            }
            else {
                hi.erase(hi.find(out));
            }
            balance();
        }

        //compute median once we have k elements in the window i>=k-1
        if (i>=k-1) {
            if (k%2==1) {
                ans.push_back(*lo.rbegin());
            }
            else {
                ans.push_back(((double)*hi.begin()+(double)*lo.rbegin())/2.0);
            }
        }
    }
    return ans;
}

//ordered set(pbds)
vector<double> slidingWindowMedian2(vector<int> nums,int k) {
    int n=nums.size();
    ordered_set<pair<ll,int>> st;
    vector<double> ans;
    ans.reserve(n-k+1);

    for (int i=0; i<n; i++) {
        //insert
        st.insert({(ll)nums[i],i});
        //remove
        st.erase({nums[i-k],i-k});
        //find median
        if (i>=k-1) {
            int size=k;
            int mid=size/2;

            if (size%2==1) {
                //odd window
                auto it=st.find_by_order(mid);
                ans.push_back((double)it->first);
            }
            else {
                auto it1=st.find_by_order(mid);
                auto it2=st.find_by_order(mid-1);
                ans.push_back(((double)it1->first+(double)it2->first)/2);
            }
        }
    }
    return ans;

}




void solve() {
    // Solution logic here
}

int main() {
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
