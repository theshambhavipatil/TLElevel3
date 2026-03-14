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

pair<vector<int>,bool> possible(vector<int> v,int mid,int n) {
    int num1=n/2;
    int num2=0;
    int count=0;
    vector<int> ans;
    // cout<<mid<<endl;

    ans.push_back(v[num1]);

    while (num1<n-1) {
        if (v[num1]>v[num2] && v[num1+1]>v[num2] && num2<(n/2)) {
            if (num2==((n/2)-1) && v.size()%2==0)
            {
                // cout<<v[num2]<<endl;
              ans.push_back(v[num2]);
            }
            else {
                count++;
                // cout<<v[num2]<<" "<<v[num1+1]<<endl;
                ans.push_back(v[num2]);
                ans.push_back(v[num1+1]);
                // cout<<v[num2]<<" ";
                num2++;
                num1++;
            }
        }
        else {
            // cout<<v[num1+1]<<endl;
            ans.push_back(v[num1+1]);
            num1++;
        }
    }

    while (num2<n/2) {
        ans.push_back(v[num2]);
        num2++;
    }
    // cout<<endl;

    if (count>=mid) {
        return {ans,true};
    }
    else {
        return {ans,false};
    }
}

void solve() {
    // Solution logic here
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int low=0;
    int high=n;
    int ans=0;
    vector<int> ans2;

    while (low<=high) {
        int mid=low+(high-low)/2;
        pair<vector<int>,bool> ans1=possible(v,mid,n);
        if (ans1.second) {
            if (mid>ans)
            {
                ans=max(ans, mid);
                ans2=ans1.first;
            }
            low=mid+1;
        }
        else {
            high=mid-1;
        }
    }

   cout << ans << endl;
    if (n==1 || n==2) {
        for (int i=0;i<v.size();i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    else{
        for (int i=0;i<ans2.size();i++) {
            cout << ans2[i] << " ";
        }
    }
    cout << endl;
}

int main() {
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